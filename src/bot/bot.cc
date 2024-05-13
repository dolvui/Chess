#include "bot.hh"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <unistd.h>
#include <limits>
#include "../node/node.hh"

namespace game {

    Bot::Bot(std::string name, bool white) {
        this->name_ = name;
        this->white_ = white;
    }

    bool compute_random(Board &board,bool white) {
        auto m = board.get_bot_legal_moves(white);
        auto it = m.cbegin();
        if (m.size() == 0)
            return false;
        srand(time(NULL));
        int random = rand() % m.size();
        std::advance(it, random);
        std::cout << "\n the bot : " << it->first.first << " , "
                  << it->first.second << " to " << it->second.first << " , "
                  << it->second.second << "\n";
        board.move(it->first.second * 8 + it->first.first,
                   it->second.first + 8 * it->second.second);
        board.print_board();
        return true;
    }

    bool Bot::compute_heuristic(Board &board, bool white) {
        return minmax(board);
        // const auto m = board.get_bot_legal_moves(white);
        // if (m.size() == 0)
        //     return false;
        // float max_heur = std::numeric_limits<float>::min();
        // auto best_move = m.begin();
        // for (auto move = m.cbegin(); move != m.cend(); move++) {
        //     Board b(board);
        //     int rt = b.move(move->first.second * 8 + move->first.first,
        //                     move->second.second * 8 + move->second.first);
        //     if (rt != 0) {
        //         continue;
        //     }
        //     float cur_heur = evaluate_board(b);
        //     if (cur_heur >= max_heur) {
        //         max_heur = cur_heur;
        //         best_move = move;
        //     }
        // }
        // board.move(best_move->first.second * 8 + best_move->first.first,
        //            best_move->second.second * 8 + best_move->second.first);
        // board.print_board();
        // return true;
    }

    bool Bot::compute_move(Board &board) {
        if (compute_ == 1)
            return compute_random(board, white_);
        //if (compute_ == 2)
        return compute_heuristic(board, white_);
    }

    float Bot::evaluate_board(Board &board) {
        float eval = 0;
        int M = (board.get_bot_legal_moves(white_).size() -
                 board.get_bot_legal_moves(!white_).size());

        for (auto p : board.get_board_()) {
            if (p) {
                eval = eval + p->get_value() * (p->is_white() ^ white_? -1 : 1);
            }
        }
        return eval + (float)M;
    }

    float compute_minmax(Node* node, int depth, bool white) {
        if(depth == 0 || node->get_childs().size() == 0)
            return node->get_value();
        if (white) {
            float value = std::numeric_limits<float>::min();
            for (auto child : node->get_childs()) {
                value = std::max(value, compute_minmax(child, depth-1,!white));
            }
            node->set_minmax_value(value);
            return value;
        } else {
            float value = std::numeric_limits<float>::max();
            for(auto child : node->get_childs())
                value = std::min(value, compute_minmax(child, depth - 1,white));
            node->set_minmax_value(value);
            return value;
        }
    }

    void Bot::construct_tree(Node &node, int depth, bool white,Board& board) {
        if (depth == 0)
            return;
        const auto m = board.get_bot_legal_moves(white);
        if (m.size() == 0)
          return;
        for (auto move = m.cbegin(); move != m.cend(); move++) {
          Board b(board);
            int rt = b.move(move->first.second * 8 + move->first.first,
                            move->second.second * 8 + move->second.first);
            if (rt != 0)
                continue;
            float cur_heur = evaluate_board(b) * (white ? -1 : 1);
            auto node_child = new Node(cur_heur, white_);
            node.add_child(node_child);
            construct_tree(*node_child,depth-1,white,b);
        }
    }
    void print_tree(Node* node,int depth = 0) {
        if (!node) return;
        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }
        std::cout << node->get_value() << std::endl;
        for (auto child : node->get_childs()) {
            print_tree(child, depth + 1);
        }
    }

    bool Bot::minmax(Board &board) {
        int d = 2;
        Board b(board);
        auto node = new Node(evaluate_board(b), white_);
        std::cout << "\nconstruct tree: \n";
        construct_tree(*node, d, white_, b);
        //print_tree(node);
        std::cout << "minmax: " << compute_minmax(node,d,white_) << "\n";
        auto l = b.get_bot_legal_moves(white_);
        auto it = l.cbegin();
        if(!white_)
            std::advance(it, node->get_index_max_val());
        else
            std::advance(it, node->get_index_min_val());
        board.move(it->first.second * 8 + it->first.first,
                   it->second.first + 8 * it->second.second);
        delete node;
        board.print_board();
        return true;
    }

    void Bot::set_compute(int c) {
        compute_ = c;
    }
} /* game */

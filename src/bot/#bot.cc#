#include "bot.hh"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <unistd.h>
#include <limits>

#include "../node/node.hh"
#include "../game/board/move.hh"


//------------GLOBAL----------------
#define MAX_FLOAT std::numeric_limits<float>::max()
#define MIN_FLOAT std::numeric_limits<float>::min()
//----------------------------------


namespace game {

    Bot::Bot(std::string name, bool white) {
        this->name_ = name;
        this->white_ = white;
    }

    bool Bot::compute_heuristic(Board &board, bool white) {
        return minmax(board);
    }

    bool Bot::compute_move(Board &board) {
        return compute_heuristic(board, white_);
    }

    float Bot::evaluate_board(Board &board) {
        float eval = 0;
        int M = (board.get_bot_legal_moves(white_).size() -
                 board.get_bot_legal_moves(!white_).size());

        for (auto p : board.get_board_()) {
            if (p) {
                eval += p->get_value() * (p->is_white() ^ white_? -1 : 1);
            }
        }
        return (eval + (float)M) * (white_? 1 : - 1);
    }

    float compute_minmax(Node* node, int depth, bool white) {
        if(depth == 0 || node->get_childs().size() == 0)
            return node->get_value();
        if (white) {
            float value = MIN_FLOAT;
            for (auto child : node->get_childs()) {
                value = std::max(value, compute_minmax(child, depth-1,!white));
            }
            node->set_minmax_value(value);
            return value;
        } else {
            float value = MAX_FLOAT;
            for(auto child : node->get_childs())
                value = std::min(value, compute_minmax(child, depth - 1,white));
            node->set_minmax_value(value);
            return value;
        }
    }


    float compute_alphabeta(Node *node,
                            bool white,float alpha,float beta) {
        if(node->get_childs().size() == 0)
          return node->get_value();
        float value;
        if (white)
        {
            value = std::numeric_limits<float>::min();
            for (auto child : node->get_childs()) {
              value = std::max(value, compute_alphabeta(child,
                                                        white, alpha, beta));
              if (beta <= value) {
                  node->set_minmax_value(value);
                  return value;
              }
              alpha = std::max(alpha,value);
            }
        } else {
            float value = std::numeric_limits<float>::max();
            for (auto child : node->get_childs()) {
              value = std::min(value, compute_alphabeta(child, !white,
                                                        alpha, beta));
              if (alpha >= value) {
                  node->set_minmax_value(value);
                  return value;
              }
              beta = std::min(beta,value);
            }
        }
        node->set_minmax_value(value);
        return value;
    }

    float Bot::compute_alphabeta_test(Node *node,int depth,Board board,
                                 bool white,float alpha,float beta)
    {
        if (depth == 0)
          return node->get_value();
        const auto m = board.get_bot_legal_moves(white);
        if (m.size() == 0)
            return node->get_value();

        float value;
        if (white)
        {
            value = MIN_FLOAT;

            for (auto move = m.cbegin(); move != m.cend(); move++) {
                Board b(board);
                int start = move->first.second * 8 + move->first.first;
                int end = move->second.second * 8 + move->second.first;
                int rt = b.move(start,end);
                if (rt != 0)
                    continue;
                float cur_heur = evaluate_board(b);
                Move* m = new Move('C',white,start,end,false,false);
                auto node_child = new Node(cur_heur, white,m);
                node->add_child(node_child);
                value = std::max(value,
                                 compute_alphabeta_test(node_child, depth - 1,
                                                        b,!white, alpha, beta));
            }
            node->set_minmax_value(value);
            return value;
        } else {
            float value = MAX_FLOAT;
            for (auto move = m.cbegin(); move != m.cend(); move++) {
                Board b(board);
                int start = move->first.second * 8 + move->first.first;
                int end = move->second.second * 8 + move->second.first;
                int rt = b.move(start,end);
                if (rt != 0)
                    continue;
                float cur_heur = evaluate_board(b);

                Move* m = new Move('C',white,start,end,false,false);
                auto node_child = new Node(cur_heur, white,m);
                node->add_child(node_child);
                value = std::min(
                    value, compute_alphabeta_test(node_child, depth - 1
                                                  ,b,!white,alpha, beta));
            }
            node->set_minmax_value(value);
            return value;
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
        auto node = new Node(evaluate_board(b), white_, nullptr);

        std::cout << "\nconstruct tree: \n";
        std::cout << "\nalphabeta:";
        std::cout << " "
                  << compute_alphabeta_test(node, d, board, white_,
                                            MAX_FLOAT,
                                            MIN_FLOAT)
        << "\n";
        // print_tree(node);

        Move *best = node->get_index_best_val();
        board.move(best->start_,best->end_);
        delete node;
        board.print_board();
        return true;
    }

    void Bot::set_compute(int c) {
        compute_ = c;
    }
} /* game */

#include "bot.hh"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
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

    float Bot::evaluate_board(Board &board,bool turn) {
        float eval = 0;
        float M = 1.5 * (float)(board.get_bot_legal_moves(turn).size() -
                                (float)board.get_bot_legal_moves(!turn).size());

        for (auto p : board.get_board_()) {
            if (p) {
                eval += p->get_value() * (!(p->is_white()^ turn)? 1 : -1);
            }
        }
        return (eval + (float)M);// * (turn? 1 : -1);
    }

    float Bot::compute_AB(Node *node, int d, bool turn, Board board,
                          float alpha, float beta) {
        if (d == 0)
          return node->get_value();
        const auto m = board.get_bot_legal_moves(turn);
        if (m.size() == 0)
           return node->get_value();

        float value = MIN_FLOAT;

        for (auto move = m.cbegin(); move != m.cend(); move++) {
            Board b(board);
            int start = move->first.second * 8 + move->first.first;
            int end = move->second.second * 8 + move->second.first;
            int rt = b.move(start,end);
            if (rt != 0)
                continue;
            float cur_heur = evaluate_board(b, turn);
            Move* m = new Move('C',turn,start,end,false,false);
            auto node_child = new Node(cur_heur, turn,m);
            node->add_child(node_child);


            value = std::max(
                value,compute_AB(node_child, d - 1, !turn, b, -beta, -alpha));
            if (value == MIN_FLOAT)
                value = node->get_value();
            if (value >= beta) {
                node->set_minmax_value(value);
                return value;
            }
            alpha = std::max(alpha,value);
        }
        if (value == MIN_FLOAT)
            value = node->get_value();
        node->set_minmax_value(value);
        return value;
    }

    void _tree_print(Node *n, Node *p, std::ofstream *fout) {
        if (n == nullptr) // rien
            return;

        if (n->get_move() == nullptr) {  //no move -> start first node
            *fout << (long)n << " [label=<start>]"
                  << ";" << std::endl;
        } else {
                *fout << (long)n << " [label=<"
                      << n->get_minmax_value() << ">]"
                      << ";" << std::endl;
                *fout << (long)p << "->" << (long)n << ";"<<std::endl;
        }
        for (auto c : n->get_childs()) {
            _tree_print(c,n,fout);
        }
    }

    void tree_print(Node *n) {
      char filename[] = "save.gv";
      std::ofstream fout(filename);
      fout << "digraph G {\n";
      _tree_print(n,nullptr,&fout);
      fout << "\n}\n";
    }
    bool Bot::minmax(Board &board) {
        int d = compute_;
        Board b(board);
        auto node = new Node(evaluate_board(b,white_), white_, nullptr);

        compute_AB(node, d, white_,board,MIN_FLOAT,MAX_FLOAT);
        // print_tree(node);
        tree_print(node);
        Move *best = node->get_index_best_val();
        if (best == nullptr)
          return false;
        sleep(1);
        board.move(best->start_,best->end_);
        delete node;
        board.print_board();
//        sleep(1);
        return true;
    }

    void Bot::set_compute(int c) {
        compute_ = c;
    }
} /* game */

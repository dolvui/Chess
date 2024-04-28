#include "bot.hh"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include <limits>

namespace game {

    Bot::Bot(std::string name, bool white) {
        this->name_ = name;
        this->white_ = white;
    }

    bool Bot::compute_move(Board &board) {
        const auto m = board.get_bot_legal_moves(white_);
        if (m.size() == 0)
            return false;
        float max_heur = std::numeric_limits<float>::min();
        auto best_move = m.begin();
        for (auto move = m.cbegin(); move != m.cend(); move++) {
          Board b(board);
//          std::cout << move._M_node;
            int rt = b.move(move->first.second * 8 + move->first.first,
                            move->second.second * 8 + move->second.first);
            if (rt != 0) {
                continue;
            }
            float cur_heur = evaluate_board(b);
            // std::cout << "\n for the move: "
            //           << move->first.second * 8 + move->first.first << " to "
            //           << move->second.second * 8 + move->second.first
            //           << "evaluate to " << cur_heur << "\n";
            if (cur_heur >= max_heur) {
                max_heur = cur_heur;
                best_move = move;
            }
        }
        board.move(best_move->first.second * 8 + best_move->first.first,
                   best_move->second.second * 8 + best_move->second.first);
        board.print_board();
        return true;
    }

    float Bot::evaluate_board(Board &board) {
        float eval = 0;
        int M = (board.get_bot_legal_moves(white_).size() -
                       board.get_bot_legal_moves(!white_).size());

        for (auto p : board.get_board_()) {
          if (p) {
            eval = eval + white_ + p->get_value() *
                (p->is_white() ^ white_?-1 : 1);
        }
        }
        return eval +M;
    }
} /* game */

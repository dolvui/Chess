#include "bot.hh"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>
namespace game {

    Bot::Bot(std::string name, bool white) {
        this->name_ = name;
        this->white_ = white;
    }

    bool Bot::compute_move(Board &board) {
      const auto m = board.get_bot_legal_moves(white_);
      // auto it = m.cbegin();
      if (m.size() == 0)
           return false;
      // srand(time(NULL));
      // int random = rand() % m.size();
      // std::advance(it, random);
      // board.move(it->first.second * 8 + it->first.first,
      //            it->second.second * 8 + it->second.first);
      // board.print_board();
      //
      // for (auto it = m.cbegin(); it != m.cend(); it++) {
      //     std::cout << "start: "<< it->first.second * 8 + it->first.first <<
      //         "emd: "<< it->second.second * 8 + it->second.first<<"\n";
      // }
        int max_heur = 0;
        std::list<std::pair<std::pair<int, int>,
                            std::pair<int, int>>>::const_iterator best_move;
        for (auto move = m.cbegin(); move != m.cend(); move++) {
          Board b(board);
          int rt = b.move(move->first.second * 8 + move->first.first,
                          move->second.second * 8 + move->second.first,false);
          if (rt != 0) {
            continue;
          }
          float cur_heur = evaluate_board(b) +
              b.get_bot_legal_moves(white_).size();
          if (cur_heur > max_heur) {
            max_heur = cur_heur;
            best_move = move;
          }
        }
        board.move(best_move->first.second * 8 + best_move->first.first,
                   best_move->second.second * 8 + best_move->second.first,true);
        board.print_board();
        return true;
    }

    float Bot::evaluate_board(Board &board) {
        float eval = 0;
        for (auto p : board.get_board_()) {
            if (p && !(p->is_white() ^ white_)) {
                eval += p->get_value();
            }
        }
        return eval;
    }
} /* game */

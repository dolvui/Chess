#include "bot.hh"
#include <iostream>

namespace game {

    Bot::Bot(std::string name,bool white) : name_(name) ,white_(white)
    {}

    bool Bot::compute_move(Board &board) {
      auto m = board.get_bot_legal_moves(white_);
      auto it = m.cbegin();
      int random = rand() % m.size();
      std::advance(it, random);
      std::cout << "\n the bot : " << it->first.first << " , "
                << it->first.second << " to " << it->second.first << " , "
                << it->second.second << "\n";
      board.move(it->first.second * 8 + it->first.first,
                 it->second.first + 8 * it->second.second);
      return true;
    }
} /* game */

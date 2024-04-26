#include "bot.hh"
#include <iostream>

namespace game {

Bot::Bot(std::string name, bool white) {
  this->name_ = name;
  this->white_ = white;
}

bool Bot::compute_move(Board &board) {
      auto m = board.get_bot_legal_moves(white_);
      auto it = m.cbegin();
      if (m.size() == 0)
          return false;
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
} /* game */

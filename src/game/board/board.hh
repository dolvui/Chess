#pragma once

#include  <list>
#include "../piece/piece.hh"
#include "../player/player.hh"

namespace game
{
class Board {
public:
    Board();
    void play();
    void print_board();
  private:
    std::list<game::Piece*>* board_;
};
} /* game */

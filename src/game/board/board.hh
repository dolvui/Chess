#pragma once

#include <array>
#include <memory>
#include "../piece/piece.hh"
#include "../player/player.hh"

namespace game
{
class Board {
public:
    Board();
    void move(int start,int end);
    void print_board();

  private:
    std::array<Piece*,64> board_;
};
} /* game */

#pragma once

#include <array>
#include <memory>
#include <utility>
#include "../piece/piece.hh"
#include "../player/player.hh"

namespace game
{
class Board {
public:
    Board();
    void move(int start,int end);
    void print_board();
    std::pair<int,int> compute_move(std::string move_not);
  private:
    std::array<Piece*,64> board_;
};
} /* game */

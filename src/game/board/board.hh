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
    int compute_move(std::string move_not, bool white);
    int find_start(char piece, bool white, int dest);
    game::Piece *get_piece(int i);
    std::list<std::pair<int, int>> get_legal_moves(bool white);
  private:
    std::array<Piece*,64> board_;
};
} /* game */

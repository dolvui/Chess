#include <algorithm>
#include <iostream>
#include <list>
#include <memory>
#include "../piece/piece.hh"
#include "../player/player.hh"
#include "board.hh"

namespace game
{
    Board::Board() : board_(std::array<Piece*,64>()) {

        auto p = new game::Piece('R', true);
        board_.at(0) = p;
     p = new game::Piece('C', true);
     board_.at(1) = p;
     p = new game::Piece('B', true);
     board_.at(2) = p;
     p = new game::Piece('K', true);
     board_.at(3) = p;
     p = new game::Piece('Q', true);
     board_.at(4) = p;
     p = new game::Piece('B', true);
     board_.at(5) = p;
     p = new game::Piece('C', true);
     board_.at(6) = p;
     p = new game::Piece('R', true);
     board_.at(7) = p;

    for (int i = 0; i < 8; i++) {
      auto p = new game::Piece('P', true);
      board_.at(8+i) = p;
    }

    for (int i = 0; i < 8; i++) {
      auto p = new game::Piece('p', false);
      board_.at(48+i) = p;
    }

    p = new game::Piece('r', false);
    board_.at(56) = p;
    p = new game::Piece('c', false);
    board_.at(57) = p;
    p = new game::Piece('b', false);
    board_.at(58) = p;
    p = new game::Piece('k', false);
    board_.at(59) = p;
    p = new game::Piece('q', false);
    board_.at(60) = p;
    p = new game::Piece('b', false);
    board_.at(61) = p;
    p = new game::Piece('c', false);
    board_.at(62) = p;
    p = new game::Piece('r', false);
    board_.at(63) = p;

}
    void Board::print_board() {
      for (int i = 0; i < 64; i++) {
          if (i != 0 && i % 8 == 0)
            std::cout << "\n";
          char p = board_.at(i) ? board_.at(i)->piece_ : ' ';
          std::cout << "|" << p << "|";
        }
    }
    void Board::move(int start, int end) {
      board_.at(end) = board_.at(start);
      board_.at(start) = nullptr;
      print_board();
    }
} /* game */

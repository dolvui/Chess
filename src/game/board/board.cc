#include <algorithm>
#include <iostream>
#include <list>
#include <memory>
#include <utility>
#include "../piece/piece.hh"

#include "../piece/bishop.hh"
#include "../piece/kig.hh"
#include "../piece/rook.hh"
#include "../piece/queen.hh"
#include "../piece/pawn.hh"
#include "../piece/knight.hh"

#include "../player/player.hh"
#include "board.hh"

namespace game
{
Board::Board() : board_(std::array<Piece *, 64>()) {
    auto p1 = new game::Rook('r', false, 0, 0, 5);
    board_.at(0) = p1;

    auto p2 = new game::Knight('n', false, 1, 0, 3);
    board_.at(1) = p2;

    auto p3 = new game::Bishop('b', false, 2, 0, 3);
    board_.at(2) = p3;


    auto p4 = new game::Queen('q', false, 3, 0, 9);
    board_.at(3) = p4;


    auto p5 = new game::Kig('k', false, 4, 0, 3);
    board_.at(4) = p2;

    auto p6 = new game::Bishop('b', false, 5, 0, 3);
    board_.at(5) = p6;

    auto p7 = new game::Knight('n', false, 6, 0, 3);
    board_.at(6) = p7;

    auto p8 = new game::Rook('r', false, 7, 0, 5);
    board_.at(7) = p8;

    for (int i = 0; i < 8; i++) {
      auto p_b = new game::Pawn('p', false, i, 1, 1);
      board_.at(i+8) = p_b;
    }

    for (int i = 0; i < 8; i++) {
        auto p_w = new game::Pawn('P', false, i, 6, 1);
        board_.at(i+48) = p_w;
    }

    auto pa = new game::Rook('R', true, 0, 7, 5);
    board_.at(56) = pa;

    auto pb = new game::Knight('N', true, 1, 7, 3);
    board_.at(57) = pb;

    auto pc = new game::Bishop('B', true, 2, 7, 3);
    board_.at(58) = pc;


    auto pd = new game::Queen('Q', true, 3, 7, 9);
    board_.at(59) = pd;


    auto pe = new game::Kig('K', true, 4, 7, 3);
    board_.at(60) = pe;

    auto pf = new game::Bishop('B', true, 5, 7, 3);
    board_.at(61) = pf;

    auto pg = new game::Knight('N', true, 6, 7, 3);
    board_.at(62) = pg;

    auto ph = new game::Rook('R', true, 7, 7, 5);
    board_.at(63) = ph;
}
    void Board::print_board() {
      for (int i = 0; i < 64; i++) {
          if (i != 0 && i % 8 == 0)
            std::cout << "\n";
          char p = ' ';
          if (board_.at(i)) {
              p = board_.at(i)->get_piece();
          }
          std::cout << "|" << p << "|";
        }
    }
    void Board::move(int start, int end) {
      board_.at(end) = board_.at(start);
      board_.at(start) = nullptr;
   }

   int Board::compute_move(std::string move_not) {
       std::string piece;
       std::string destination;

       if (islower(move_not[0])) {
           piece = "p";
           destination = move_not.substr(0, 2);
       } else {
           piece = move_not.substr(0, 1);
           destination = move_not.substr(1, 2);
       }
       std::cout << "P:" << piece << " dest:" << destination << "\n\n";
       //return make_pair(piece, destination);
//       move(48+4,7*4+4);
       return 0;
    }
} /* game */

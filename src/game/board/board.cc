#include <iostream>
#include  <list>
#include "../piece/piece.hh"
#include "../player/player.hh"
#include "board.hh"

namespace game
{
Board::Board() : board_(new std::list<game::Piece *>(64)) {

    auto p = new game::Piece('R', true);
    board_->push_front(p);
    p = new game::Piece('C', true);
    board_->push_front(p);
    p = new game::Piece('B', true);
    board_->push_front(p);
    p = new game::Piece('K', true);
    board_->push_front(p);
    p = new game::Piece('Q', true);
    board_->push_front(p);
    p = new game::Piece('B', true);
    board_->push_front(p);
    p = new game::Piece('K', true);
    board_->push_front(p);
    p = new game::Piece('R', true);
    board_->push_front(p);

    for (int i = 0; i < 8; i++) {
      auto p = new game::Piece('P', true);
      board_->push_front(p);
    }

    for (int i = 0; i < 4*8; i++) {
      auto p = new game::Piece(' ',false);
      board_->push_front(p);
    }

    for (int i = 0; i < 8; i++) {
      auto p = new game::Piece('p', false);
      board_->push_front(p);
    }

    p = new game::Piece('r', false);
    board_->push_front(p);
    p = new game::Piece('c', false);
    board_->push_front(p);
    p = new game::Piece('b', false);
    board_->push_front(p);
    p = new game::Piece('k', false);
    board_->push_front(p);
    p = new game::Piece('q', false);
    board_->push_front(p);
    p = new game::Piece('b', false);
    board_->push_front(p);
    p = new game::Piece('k', false);
    board_->push_front(p);
    p = new game::Piece('r', false);
    board_->push_front(p);

}
    void Board::play(){}
    void Board::print_board() {
        int i = 0;
        for (game::Piece* p : *board_) {
          std::cout << "|" << p->piece_ << "|";
          i++;
          if (i % 8 == 0)
              std::cout << "\n";
          if (i > 63)
              return;
        }
    }
} /* game */

#include "pawn.hh"
#include "piece.hh"
#include <list>
#include <utility>

namespace game {

Pawn::Pawn(char piece, bool white, int x, int y, int value) {
     this->piece_ = piece;
  this->white_ = white;
  this->x_ = x;
  this->y_ = y;
  this->value_ = value;
}

    std::list<std::pair<int, int>> Pawn::compute_move() {
      auto rep = std::list<std::pair<int, int>>();

      if (white_) {
          rep.push_front(std::pair<int, int>(x_ + 1, y_));
          rep.push_front(std::pair<int, int>(x_ + 2, y_));
          rep.push_front(std::pair<int, int>(x_ + 1, y_ + 1));
          rep.push_front(std::pair<int, int>(x_ + 1, y_ + 1));
      }
      else {
          rep.push_front(std::pair<int, int>(x_ - 1, y_));
          rep.push_front(std::pair<int, int>(x_ - 2, y_));
          rep.push_front(std::pair<int, int>(x_ - 1, y_ - 1));
          rep.push_front(std::pair<int, int>(x_ - 1, y_ - 1));
      }
      return rep;
    }
} /* game */

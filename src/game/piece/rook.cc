#include "rook.hh"
#include "piece.hh"
#include <list>
#include <utility>

namespace game {

Rook::Rook(char piece, bool white, int x, int y, int value) {
  this->piece_ = piece;
  this->white_ = white;
  this->x_ = x;
  this->y_ = y;
  this->value_ = value;
}

    std::list<std::pair<int, int>> Rook::compute_move(std::array<Piece*,64>&) {
      auto rep = std::list<std::pair<int, int>>();

      int i = x_ + 1;
      while (i < 8) {
          rep.push_front(std::pair<int, int>(i, y_));
          i++;
      }

      int j = y_ + 1;
      while (j < 8) {
          rep.push_front(std::pair<int, int>(x_, j));
          j++;
      }

      i = x_ - 1;
      while (i >= 0) {
          rep.push_front(std::pair<int, int>(i, y_));
          i--;
      }

      j = y_ - 1;
      while (j >= 0) {
          rep.push_front(std::pair<int, int>(x_, j));
          j--;
      }

        return rep;
    }
} /* game */

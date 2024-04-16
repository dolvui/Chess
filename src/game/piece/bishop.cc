#include "bishop.hh"
#include "piece.hh"
#include <list>
#include <utility>

namespace game {

Bishop::Bishop(char piece, bool white, int x, int y, int value) {
     this->piece_ = piece;
  this->white_ = white;
  this->x_ = x;
  this->y_ = y;
  this->value_ = value;
}

    std::list<std::pair<int, int>> Bishop::compute_move() {
      auto rep = std::list<std::pair<int, int>>();

      int i = x_ + 1;
      int j = y_ + 1;
      while (i < 8 && j < 8) {
          rep.push_front(std::pair<int, int>(i, j));
          i++;
          j++;
      }

      i = x_ - 1;
      j = y_ - 1;
      while (i >= 0  && j >= 0) {
          rep.push_front(std::pair<int, int>(i, j));
          i--;
          j--;
      }

      i = x_ + 1;
      j = y_ - 1;
      while (i < 8  && j >= 0) {
          rep.push_front(std::pair<int, int>(i, j));
          i++;
          j--;
      }

      i = x_ - 1;
      j = y_ + 1;
      while (i >= 0  && j < 8) {
          rep.push_front(std::pair<int, int>(i, j));
          i--;
          j++;
      }

        return rep;
    }
} /* game */

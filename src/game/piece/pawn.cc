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
        rep.push_front(std::pair<int, int>(x_, y_ - 1));
        if (en_passant) {
            rep.push_front(std::pair<int, int>(x_ - 1, y_ -1));
            rep.push_front(std::pair<int, int>(x_ - 1, y_ - 1));
        }
          if (started) {
            rep.push_front(std::pair<int, int>(x_, y_ - 2));
          }
      }
      else {
        rep.push_front(std::pair<int, int>(x_, y_ + 1));
        if (en_passant) {
            rep.push_front(std::pair<int, int>(x_ + 1, y_ + 1));
            rep.push_front(std::pair<int, int>(x_ + 1, y_ + 1));
        }
          if (started) {
            rep.push_front(std::pair<int, int>(x_, y_ + 2));
          }
      }
      return rep;
    }

    void Pawn::has_moved() {
        started = false;
    }
} /* game */

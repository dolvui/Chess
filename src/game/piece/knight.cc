#include "knight.hh"
#include "piece.hh"
#include <list>
#include <utility>

namespace game {

Knight::Knight(char piece, bool white, int x, int y, int value) {
    this->piece_ = piece;
    this->white_ = white;
    this->x_ = x;
    this->y_ = y;
    this->value_ = value;
}

std::list<std::pair<int, int>>
Knight::compute_move(std::array<Piece*,64>&) {
        auto rep = std::list<std::pair<int, int>>();
        rep.push_front(std::pair<int, int>(x_ +2 , y_ + 1));
        rep.push_front(std::pair<int, int>(x_ +2, y_ - 1));

        rep.push_front(std::pair<int, int>(x_ +1 , y_ -2 ));
        rep.push_front(std::pair<int, int>(x_ + 1, y_+ 2));

        rep.push_front(std::pair<int, int>(x_ - 2, y_ + 1));
        rep.push_front(std::pair<int, int>(x_ - 2, y_ - 1));

        rep.push_front(std::pair<int, int>(x_ - 1, y_ -2 ));
        rep.push_front(std::pair<int, int>(x_ - 1, y_ + 2));

        return rep;
    }
} /* game */

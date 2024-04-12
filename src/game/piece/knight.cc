#include "knight.hh"
#include "piece.hh"
#include <list>
#include <utility>

namespace game {

    Knight::Knight(char piece, bool white, int x, int y, int value)
    : piece_(piece) , white_(white) , x_(x) , y_(y) , value_(value){}

    std::list<std::pair<int, int>> Knight::compute_move() {
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

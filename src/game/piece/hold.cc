#include "hold.hh"
#include "piece.hh"
#include <list>
#include <utility>

namespace game {

    Hold::Hold(char piece, bool white, int x, int y, int value) {
        this->piece_ = piece;
        this->white_ = white;
        this->x_ = x;
        this->y_ = y;
        this->value_ = value;
    }

    std::list<std::pair<int, int>> Hold::compute_move(game::Board &board) {
        return std::list<std::pair<int, int>>();
    }
} /* game */

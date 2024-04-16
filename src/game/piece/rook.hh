#pragma once

#include <utility>
#include <list>
#include "piece.hh"

namespace game
{
    class Rook : public Piece {
    public:
        Rook(char piece,bool white,int x,int y,int value);
        std::list<std::pair<int, int>> compute_move() override;
//        char piece_;
//        bool white_;
//        int x_;
//        int y_;
//        int value_;
};
} // namespace game

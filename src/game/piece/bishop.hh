#pragma once

#include <utility>
#include <list>
#include "piece.hh"

namespace game
{
    class Bishop : public Piece {
    public:
        Bishop(char piece,bool white,int x,int y,int value);
        std::list<std::pair<int, int>> compute_move() override;
};
} // namespace game

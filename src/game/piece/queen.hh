#pragma once

#include <utility>
#include <list>
#include "piece.hh"

namespace game
{
    class Queen : public Piece {
    public:
        Queen(char piece,bool white,int x,int y,int value);
        std::list<std::pair<int, int>> compute_move() override;
        void has_moved() override {};
};
} // namespace game

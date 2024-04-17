#pragma once

#include <utility>
#include <list>
#include "piece.hh"

namespace game
{
    class Rook : public Piece {
    public:
        Rook(char piece,bool white,int x,int y,int value);
        std::list<std::pair<int, int>>
        compute_move(std::array<Piece*,64>&) override;
        void has_moved() override{};
};
} // namespace game

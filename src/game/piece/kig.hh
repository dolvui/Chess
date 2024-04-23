#pragma once

#include <utility>
#include <list>
#include "piece.hh"

namespace game
{
    class Kig : public Piece {
    public:
        Kig(char piece,bool white,int x,int y,int value);
        std::list<std::pair<int, int>>
        compute_move(game::Board& board, bool legal) override;
        void has_moved() override{};
};
} // namespace game

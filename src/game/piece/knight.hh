#pragma once

#include <utility>
#include <list>
#include "piece.hh"

namespace game
{
    class Knight : public Piece {
    public:
        Knight(char piece,bool white,int x,int y,int value);
        std::list<std::pair<int, int>>
        compute_move(game::Board& board, bool legal) override;
        void has_moved() override{};
};
} // namespace game

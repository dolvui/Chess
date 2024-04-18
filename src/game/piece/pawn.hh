#pragma once

#include <utility>
#include <list>
#include "piece.hh"

namespace game
{
    class Pawn : public Piece {
    public:
        Pawn(char piece,bool white,int x,int y,int value);
        std::list<std::pair<int, int>>
        compute_move(game::Board& board) override;
        void has_moved() override {};
      private:
};
} // namespace game

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
        compute_move(game::Board& board,bool legal) override;
        void has_moved() override{};
        void set_pos(int pos);
      private:
};
} // namespace game

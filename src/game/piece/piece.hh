#pragma once

#include <utility>
#include <list>
#include <array>

#include "../board/board.hh"

namespace game {
    class Board;
    class Piece {
    public:
        virtual std::list<std::pair<int, int>>
        compute_move(game::Board& board) = 0;
        virtual void has_moved() = 0;
        char get_piece();
        bool is_white();
        int get_x();
        int get_y();
        int get_value();

        void set_x(int x);
        void set_y(int y);
        void set_pos(int pos);

    protected:
        Piece() = default;
        char piece_;
        bool white_;
        int x_;
        int y_;
        int value_;
    };
} // namespace game

#include "piece.hxx"

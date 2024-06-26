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
        compute_move(game::Board& board, bool legal) = 0;
        virtual void has_moved() = 0;
        char get_piece();
        bool is_white();
        int get_x();
        int get_y();
        float get_value();
        bool get_started();

        void set_x(int x);
        void set_y(int y);
        void set_pos(int pos);
        bool legit(int i, int j);
    protected:
        Piece() = default;
        char piece_;
        bool white_;
        int x_;
        int y_;
        float value_;
        int raw_value_;
        bool is_started = true;
        std::array<float,64> weights_;
    };
} // namespace game

#include "piece.hxx"

#pragma once

#include <utility>
#include <list>

namespace game
{
class Piece {
public:
    virtual std::list<std::pair<int, int>> compute_move(){}
    Piece(char piece, bool white, int x, int y, int value);
    Piece() = default;
    ~Piece() = default;
    char get_piece();
    bool is_white();
    int get_x();
    int get_y();
    int get_value();

    void set_x(int x);
    void set_y(int y);
//protected:
    char piece_;
    bool white_;
    int x_;
    int y_;
    int value_;
};
} // namespace game

#include "piece.hxx"

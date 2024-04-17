#pragma once

#include <utility>
#include <list>

namespace game
{
class Piece {
public:
    virtual std::list<std::pair<int, int>> compute_move() = 0;
    virtual void has_moved() = 0;
    // Piece(char piece, bool white, int x, int y, int value);
    //Piece() = default;
    char get_piece();
    bool is_white();
    int get_x();
    int get_y();
    int get_value();

    void set_x(int x);
    void set_y(int y);
    void set_pos(int pos);
protected:
    char piece_;
    bool white_;
    int x_;
    int y_;
    int value_;
};
} // namespace game

#include "piece.hxx"

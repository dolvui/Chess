#pragma once

#include <vector>
#include <string>
#include "../board/board.hh"

namespace game {
    class Board;
class Player{
public:
    Player() = default;
    Player(std::string name,bool white);
    ~Player() = default;
    virtual bool compute_move(Board &board);
    std::string get_name();
    void win();
    void loose();
    void draw();
  protected:
    std::string name_;
    bool white_;
};
} /* game */

#include "player.hxx"

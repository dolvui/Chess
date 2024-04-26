#pragma once

#include <vector>
#include <string>
#include "../game/player/player.hh"
#include "../game/board/board.hh"
namespace game
{
    class Bot : public Player{
    public:
        Bot(std::string name,bool white);
        // Bot(){};
        // ~Bot(){};
        bool compute_move(Board& board) override;
        //std::string get_name();
    // private:
    //     std::string name_;
    //     bool white_;
};
} /* game */
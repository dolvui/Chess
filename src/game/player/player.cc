#include "player.hh"
#include <iostream>

namespace game
{
    Player::Player(std::string name) : name_(name) {}

    std::string Player::get_name() {
        return name_;
    }
} /* game */

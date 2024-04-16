#pragma once

#include <vector>
#include <string>
#include "../piece/piece.hh"

namespace game
{
class Player{
public:
    Player(std::string name);
    ~Player() = default;
    std::string get_name();
  private:
    std::string name_;
};
} /* game */

#include "player.hxx"

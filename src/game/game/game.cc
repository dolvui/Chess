
#include "../board/board.hh"
#include "game.hh"
#include <iostream>
#include <sstream>
#include <string>

namespace game {
    Game::Game(Board& board) : board_(board)
{}
    void Game::play() {
      int s;
      int e;

      std::cin>> s;
      std::cin >> e;
      board_.move(s,e);
    }
}

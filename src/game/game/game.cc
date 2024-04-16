
#include "../board/board.hh"
#include "game.hh"
#include <iostream>
#include <sstream>
#include <string>

namespace game {
    Game::Game(Board& board) : board_(board)
{}
    void Game::play() {

      std::string input = "";
      while (input.compare("exit") != 0) {
          std::cout << "\n\n make a move:";
          std::cin >> input;
          std::cout << "\n\n";
          if (input.compare("exit") == 0)
              break;
          board_.compute_move(input);
          board_.print_board();
      }
      std::cout << "\n\n End of the game \n";
    }
}

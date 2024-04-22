
#include "../board/board.hh"
#include "game.hh"
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

namespace game {
    Game::Game(Board &board,game::Player white_player,game::Player black_player)
        : board_(board), white_player_(white_player),
          black_player_(black_player) {}
    void Game::play() {
        std::string input = "";
        int move = 0;
        while (input.compare("exit") != 0) {
            if(move%2 == 0)
                std::cout << "\n\n " << white_player_.get_name() <<
                    " with the white pieces to move: ";
            else
                std::cout << "\n\n " << black_player_.get_name() <<
                    " with the black pieces to move: ";
            std::cin >> input;
            std::cout << "\n\n";
            if (input.compare("exit") == 0)
                break;
            if (board_.compute_move(input, move % 2 == 0) != 0)
                std::cout << "error move\n";
            else
                move++;
            board_.print_board();
        }
        std::cout << "\n\n End of the game \n";
    }
}

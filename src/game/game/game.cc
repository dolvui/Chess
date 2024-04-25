
#include "../board/board.hh"
#include "game.hh"
#include "../../bot/bot.hh"
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

namespace game {
Game::Game(Board &board, game::Player white_player,
           game::Player black_player)
        : board_(board), white_player_(white_player),
          black_player_(black_player) {}


    void Game::play() {
        int move = 0;

        while (true) {
            if (!white_player_.compute_move(board_)) {
              black_player_.win();
              white_player_.loose();
              break;
            }
            move++;
            if (!black_player_.compute_move(board_)) {
              white_player_.win();
              black_player_.loose();
              break;
            }
            move++;
        }
        std::cout << "\n\n End of the game \n";
    }
}

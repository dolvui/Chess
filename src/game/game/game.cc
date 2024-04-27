
#include "../board/board.hh"
#include "game.hh"
#include "../../bot/bot.hh"
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

namespace game {
Game::Game(Board& board, game::Player* white_player, game::Player* black_player,
           game::Player* white_bot, game::Player* black_bot)
    : board_(board), white_player_(white_player), black_player_(black_player),
      white_bot_(white_bot) , black_bot_(black_bot){}

    void Game::play() {
        int move = 0;

        while (true) {
          if (white_player_ && !white_player_->compute_move(board_) ||
              white_bot_ && !white_bot_->compute_move(board_)) {
            if (!board_.is_in_check(true)) {
                std::cout << "\n Nice stalemate ! \n   DRAW   \n";
                break;
            }
              if (black_player_)
                  black_player_->win();
              else
                  black_bot_->win();

              if (white_player_)
                  white_player_->loose();
              else
                  white_bot_->loose();
              break;
          }
           if (board_.not_enough_material()) {
                std::cout << "\n Not enough materials ! \n   DRAW   \n";
                break;
            }
            move++;
            if (black_player_ && !black_player_->compute_move(board_) ||
                black_bot_ && !black_bot_->compute_move(board_)) {
              if (!board_.is_in_check(false)) {
                  std::cout << "\n Nice stalemate ! \n   DRAW   \n";
                    break;
                }
                if (white_player_)
                  white_player_->win();
                else
                  white_bot_->win();

                if (black_player_)
                  black_player_->win();
                else
                  black_bot_->loose();

              break;
            }
            if (board_.fifty_rule()) {
              std::cout << "\n fifty rules ,"
                        << "not capture of pawn moves in the last 50 moves ! "
                           "\n   DRAW   \n";
              board_.print_moves();
              break;
            }
            if (board_.not_enough_material()) {
                std::cout << "\n Not enough materials ! \n   DRAW   \n";
                break;
            }
            move++;
        }
//        int lm = board_.print_moves();
        std::cout << "\n\n End of the game \n";
    }
}

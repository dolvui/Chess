#pragma once

#include "../board/board.hh"
#include "../player/player.hh"
#include "../../bot/bot.hh"

namespace game {
    class Game {
    public:
      Game(Board& board, game::Player* white_player, game::Player* black_player,
           game::Player* white_bot,game::Player* black_bot);
        void play();
//    void apply_check(bool white);
    private:
        game::Board board_;
        game::Player* white_player_;
        game::Player* black_player_;
        game::Player* white_bot_;
        game::Player* black_bot_;
    };
}

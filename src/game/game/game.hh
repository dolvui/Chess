#pragma once

#include "../board/board.hh"
#include "../player/player.hh"
namespace game {
class Game {
public:
    Game(Board& board,game::Player white_player ,game::Player black_player);
    void play();
//    void apply_check(bool white);
private:
    game::Board board_;
    game::Player white_player_;
    game::Player black_player_;
};
}

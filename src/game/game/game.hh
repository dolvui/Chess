#pragma once

#include "../board/board.hh"

namespace game {
class Game {
public:
    Game(Board& board);
    void play();
private:
    game::Board board_;
};
}

#include<iostream>
#include "game/board/board.hh"
#include "game/game/game.hh"
int main() {
    std::cout << "lets go" << std::endl;
    game::Board b = game::Board();
    b.print_board();

    game::Game G = game::Game(b);
    G.play();
    return 0;
}

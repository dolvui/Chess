#include<iostream>
#include "game/board/board.hh"
#include "game/game/game.hh"
#include "game/piece/bishop.hh"
#include "game/piece/knight.hh"
#include "game/piece/piece.hh"
#include "game/piece/queen.hh"
#include "game/piece/rook.hh"
#include "game/piece/kig.hh"
#include "game/piece/pawn.hh"

int main() {
    std::cout << "lets go" << std::endl;
    game::Board b = game::Board();
    b.print_board();

    game::Game G = game::Game(b);
    G.play();
    return 0;
}

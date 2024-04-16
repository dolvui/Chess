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
#include "game/player/player.hh"

int main() {
    std::cout << "lets go" << std::endl;
    game::Board b = game::Board();

    std::string name1;
    std::string name2;

    std::cout << "\nwhite name: ";
    std::cin >> name1;

    std::cout << "\nblack name: ";
    std::cin >> name2;

    game::Player white_player = game::Player(name1);
    game::Player black_player = game::Player(name2);

    game::Game G = game::Game(b, white_player, black_player);

    b.print_board();
    G.play();
    return 0;
}

#include<iostream>
#include "game/board/board.hh"
#include "game/game/game.hh"
#include "game/piece/knight.hh"
#include "game/piece/piece.hh"

int main() {
    std::cout << "lets go" << std::endl;
    //game::Board b = game::Board();
    //b.print_board();

    // game::Game G = game::Game(b);
    // G.play();

    auto p = new game::Knight('K',true,4,4,3);
    auto l = p->compute_move();
    for (auto it = l.begin(); it != l.end(); it++) {
        std::cout << "move: (" << it->first << " , " << it->second << " )\n";
    }
    return 0;
}

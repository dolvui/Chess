#include<iostream>
#include "game/board/board.hh"

int main() {
    std::cout << "lets go" << std::endl;
    game::Board b = game::Board();
    b.print_board();
    return 0;
}

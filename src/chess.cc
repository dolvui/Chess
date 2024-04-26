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
#include "bot/bot.hh"

int main() {
    std::cout <<"\n  -white--|--black-\n";
    std::cout << "1. player vs player\n";
    std::cout << "2. player vs bot\n";
    std::cout << "3. bot    vs player\n";
    std::cout << "4. bot    vs bot\n\n";

    std::cout << "mode: ";

    int mode;

    std::cin >> mode;

    game::Player* white_player =  nullptr;;
    game::Player *black_player = nullptr;
    game::Bot* white_bot =  nullptr;;
    game::Bot* black_bot = nullptr;
    game::Board b = game::Board();

    std::string name1;
    std::string name2;

    if (mode <= 2) {
        std::cout << "\nwhite name: ";
        std::cin >> name1;
        white_player = new game::Player(name1,true);
    }
    else {
        white_bot = new game::Bot("Jeff",true);
    }

    if (mode % 2 == 1) {
        std::cout << "\black name: ";
        std::cin >> name2;
        black_player = new game::Player(name2,false);
    }
    else {
        black_bot = new game::Bot("Jeff",false);
    }

    auto g = game::Game(b,white_player,black_player,white_bot,black_bot);
    b.print_board();
    g.play();

    return 0;
}

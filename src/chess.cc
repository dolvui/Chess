#include <iostream>
#include <getopt.h>

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


int main(int argc, char *argv[]) {

    int mode = 0;


    option longopts[] = {
        {"mode", required_argument, NULL, 'm'},
        {"help", no_argument, NULL, 'h'}, {0}};

    while (1) {
        const int opt = getopt_long(argc, argv, "mh::", longopts, 0);
        if (opt == -1) {
            break;
        }

        switch (opt) {
        case 'm':
            mode =  4;
//          std::cout << optarg;
          break;
        case 'h':
        default:
          std::cout << "\nUsage: ./chess [-m <mode>]\n";
          break;
        }
    }

    if (mode == 0) {
        std::cout <<"\n  -white--|--black-\n";
        std::cout << "1. player vs player\n";
        std::cout << "2. player vs bot\n";
        std::cout << "3. bot    vs player\n";
        std::cout << "4. bot    vs bot\n\n";

        std::cout << "mode: ";

        std::cin >> mode;

    }
    std::cout << "\nYou select mode " << mode << " !\n";

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
      white_bot = new game::Bot("Victor", true);
      white_bot->set_compute(2);
    }

    if (mode % 2 == 1) {
        std::cout << "\nblack name: ";
        std::cin >> name2;
        black_player = new game::Player(name2,false);
    }
    else {
      black_bot = new game::Bot("Vivi", false);
      black_bot->set_compute(2);
    }

    auto g = game::Game(b,white_player,black_player,white_bot,black_bot);
    b.print_board();
    g.play();

    return 0;
}

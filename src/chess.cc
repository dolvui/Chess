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

#include <chrono>

int main() {

    // std::string name1;
    // std::string name2;

    // std::cout << "\nwhite name: ";
    // std::cin >> name1;

    // std::cout << "\nblack name: ";
    // std::cin >> name2;

    int loop;

    std::cin >> loop;
    // game::Player white_player = game::Player(name1,true);
    // game::Player black_player = game::Player(name2,false);
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < loop; i++) {
        game::Board b = game::Board();
        game::Bot bot = game::Bot("jeff", false);
        game::Bot bot2 = game::Bot("jeffrey",true);
        // game::Game G = game::Game(b, white_player, nullptr, nullptr, bot);
        auto g = game::Game(b,nullptr,nullptr,&bot2,&bot);
        b.print_board();
        g.play();
    }
    auto t2 = std::chrono::high_resolution_clock::now();

    std::cout << loop << " games took "
              << std::chrono::duration_cast
        <std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";

    return 0;
}

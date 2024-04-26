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

    std::string name1;
    std::string name2;

    std::cout << "\nwhite name: ";
    std::cin >> name1;

    std::cout << "\nblack name: ";
    std::cin >> name2;

    game::Player white_player = game::Player(name1,true);
    game::Player black_player = game::Player(name2,false);

    game::Board b = game::Board();
    game::Bot bot = game::Bot("jeff", false);
//        game::Bot bot2 = game::Bot("jeffrey",true);
    // game::Game G = game::Game(b, white_player, nullptr, nullptr, bot);
    auto g = game::Game(b,&white_player,&black_player,nullptr,nullptr);
    b.print_board();
    g.play();

    return 0;
}

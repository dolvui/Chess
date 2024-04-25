#include "player.hh"
#include <iostream>

namespace game
{
    Player::Player(std::string name,bool white) : name_(name) , white_(white) {}

    bool Player::compute_move(Board &board) {
      std::string input = "";

      std::cout << "you got "
                << board.get_legal_moves(white_).size()
                << " legal moves, use it with wisdom ..\n";

        if (board.get_legal_moves(white_).size() == 0) {
            std::cout << "\n no legal moves\n";
            return false;
        }
        do {
            if(white_)
                std::cout << "\n\n " << name_ <<
                    " with the white pieces to move: ";
            else
                std::cout << "\n\n " << name_ <<
                    " with the black pieces to move: ";
            std::cin >> input;
        } while (board.compute_move(input, white_) != 0);
        board.print_board();
        return true;
    }

    void Player::win() {
        std::cout << "\n\n " << name_
                  << " win by checkmate\n";
    }
    void Player::loose() {
        std::cout << "\n\n " << name_
                  << " was defeated ;( \n";
    }
    void Player::draw(){}
    std::string Player::get_name() {
        return name_;
    }
} /* game */

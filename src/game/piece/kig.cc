#include "kig.hh"
#include "piece.hh"
#include <list>
#include <utility>

namespace game {

    Kig::Kig(char piece, bool white, int x, int y, int value) {
        this->piece_ = piece;
        this->white_ = white;
        this->x_ = x;
        this->y_ = y;
        this->value_ = value;
    }

    std::list<std::pair<int, int>>
    Kig::compute_move(game::Board& board) {
        auto rep = std::list<std::pair<int, int>>();

        if(board.is_adv_piece(x_ + 1,y_,white_))
            rep.push_front(std::pair<int, int>(x_ + 1, y_));

        if(board.is_adv_piece(x_ - 1,y_,white_))
            rep.push_front(std::pair<int, int>(x_ - 1, y_));
        if(board.is_adv_piece(x_,y_+ 1,white_))
            rep.push_front(std::pair<int, int>(x_, y_ + 1));
        if(board.is_adv_piece(x_,y_ - 1,white_))
            rep.push_front(std::pair<int, int>(x_, y_ - 1));

        if(board.is_adv_piece(x_ + 1, y_ + 1,white_))
            rep.push_front(std::pair<int, int>(x_ + 1, y_ + 1));

        if(board.is_adv_piece(x_ + 1,y_ - 1,white_))
            rep.push_front(std::pair<int, int>(x_ + 1, y_ - 1));

        if(board.is_adv_piece(x_ - 1,y_ + 1,white_))
            rep.push_front(std::pair<int, int>(x_ - 1, y_ + 1));

        if(board.is_adv_piece(x_ - 1,y_ - 1,white_))
            rep.push_front(std::pair<int, int>(x_ - 1, y_ - 1));

        if (is_started && board.can_big_castle(x_, y_, x_ - 2)) {
            rep.push_front(std::pair<int, int>(x_ - 2, y_));
        }
        if (is_started && board.can_lil_castle(x_, y_, x_ + 2)) {
            rep.push_front(std::pair<int, int>(x_ + 2, y_));
        }
        return rep;
    }
} /* game */

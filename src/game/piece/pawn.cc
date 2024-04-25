#include "pawn.hh"
#include "piece.hh"
#include <iostream>
#include <list>
#include <utility>

namespace game {

    Pawn::Pawn(char piece, bool white, int x, int y, int value) {
        this->piece_ = piece;
        this->white_ = white;
        this->x_ = x;
        this->y_ = y;
        this->value_ = value;
    }

    std::list<std::pair<int, int>>
    Pawn::compute_move(game::Board& board,bool legal) {
        auto rep = std::list<std::pair<int, int>>();
        int dir = 1;
        if (white_)
            dir = -1;

        if ( board.is_move_legal(white_,legal,x_,y_,x_,y_ + dir)
             && board.is_piece_move(x_, y_ + dir, white_)) {
            rep.push_front(std::pair<int, int>(x_, y_ + dir));

            if (board.is_move_legal(white_, legal, x_, y_, x_, y_ + 2*dir) &&
                is_started && board.is_piece_move(x_, y_ + 2*dir, white_))
                rep.push_front(std::pair<int, int>(x_, y_ + 2*dir));
        }

        if( board.is_move_legal(white_,legal,x_,y_,x_ + 1,y_ + dir)
            && board.is_capt_piece(x_ + 1,y_ + dir,white_))
            rep.push_front(std::pair<int, int>(x_ + 1, y_ + dir));

        if( board.is_move_legal(white_,legal,x_,y_,x_ - 1,y_ + dir)
            && board.is_capt_piece(x_ - 1,y_ + dir,white_))
            rep.push_front(std::pair<int, int>(x_ - 1, y_ + dir));
        return rep;
    }
} /* game */

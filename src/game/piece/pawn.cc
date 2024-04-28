#include "pawn.hh"
#include "piece.hh"
#include <array>
#include <iostream>
#include <list>
#include <utility>

namespace game {

    Pawn::Pawn(char piece, bool white, int x, int y, int value) {
        this->piece_ = piece;
        this->white_ = white;
        this->x_ = x;
        this->y_ = y;
        this->raw_value_ = value;
        if(!white)
            this->weights_ = {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.5,
                              1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.1,
                              1.1,1.2,1.3,1.3,1.2,1.1,1.1,1.05,
                              1.05,1.1,1.25,1.25,1.1,1.05,1.05,1.0,
                              1.0,1.0,1.2,1.2,1.0,1.0,1.0,1.05,
                              0.95,0.9,1.0,1.0,0.9,0.95,1.05,1.05,
                              1.1,1.1,0.8,0.8,1.1,1.1,1.05,1.0,
                              1.0,1.0,1.0,1.0,1.0,1.0,1.0};
        else
            this->weights_ = {
                1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, 1.05, 1.1, 1.1,
                0.8,  0.8,  1.1,  1.1,  1.05, 1.05, 0.95, 0.9, 1.0,  1.0, 0.9,
                0.95, 1.05, 1.0,  1.0,  1.0,  1.2,  1.2,  1.0, 1.0,  1.0, 1.05,
                1.05, 1.1,  1.25, 1.25, 1.1,  1.05, 1.05, 1.1, 1.1,  1.2, 1.3,
                1.3,  1.2,  1.1,  1.1,  1.5,  1.5,  1.5,  1.5, 1.5,  1.5, 1.5,
                1.5,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, 1.0};
        this->value_ = raw_value_ * weights_[y*8 +x];
    }

    std::list<std::pair<int, int>>
    Pawn::compute_move(game::Board& board,bool legal) {
        auto rep = std::list<std::pair<int, int>>();
        int dir = 1;
        if (white_)
            dir = -1;

        if (legit(x_, y_ + dir) &&
            board.is_move_legal(white_,legal,x_,y_,x_,y_ + dir)
            && board.is_piece_move(x_, y_ + dir, white_)) {
            rep.push_front(std::pair<int, int>(x_, y_ + dir));

            if (legit(x_, y_ + 2 * dir) &&
                board.is_move_legal(white_, legal, x_, y_, x_, y_ + 2*dir) &&
                is_started && board.is_piece_move(x_, y_ + 2*dir, white_))
                rep.push_front(std::pair<int, int>(x_, y_ + 2*dir));
        }

        if (legit(x_ + 1, y_ + dir) &&
            board.is_move_legal(white_, legal, x_, y_, x_ + 1, y_ + dir) &&
            (board.is_capt_piece(x_ + 1, y_ + dir, white_) ||
             board.can_enpassant(x_, y_, x_ + 1, y_ + dir,white_)) )
            rep.push_front(std::pair<int, int>(x_ + 1, y_ + dir));

        if (legit(x_ - 1, y_ + dir) &&
            board.is_move_legal(white_, legal, x_, y_, x_ - 1, y_ + dir) &&
            (board.is_capt_piece(x_ - 1, y_ + dir, white_) ||
             board.can_enpassant(x_, y_, x_ - 1, y_ + dir,white_) ))
            rep.push_front(std::pair<int, int>(x_ - 1, y_ + dir));
        return rep;
    }
} /* game */

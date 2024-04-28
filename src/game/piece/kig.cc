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
        this->raw_value_ = value;
        if(!white)
            this->weights_ = {0.7,0.6,0.6,0.5,0.5,0.6,0.6,0.7,0.7,
                              0.6,0.6,0.5,0.5,0.6,0.6,0.7,0.7,
                              0.6,0.6,0.5,0.5,0.6,0.6,0.7,0.7,
                              0.6,0.6,0.5,0.5,0.6,0.6,0.7,0.8,
                              0.7,0.7,0.6,0.6,0.7,0.7,0.8,0.9,
                              0.8,0.8,0.8,0.8,0.8,0.8,0.9,1.2,
                              1.2,1.0,1.0,1.0,1.0,1.2,1.2,1.2,
                              1.3,1.1,1.0,1.0,1.1,1.3,1.2};
        else
          this->weights_ = {
              1.2, 1.3, 1.1, 1.0, 1.0, 1.1, 1.3, 1.2, 1.2, 1.2, 1.0, 1.0, 1.0,
              1.0, 1.2, 1.2, 0.9, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.9, 0.8, 0.7,
              0.7, 0.6, 0.6, 0.7, 0.7, 0.8, 0.7, 0.6, 0.6, 0.5, 0.5, 0.6, 0.6,
              0.7, 0.7, 0.6, 0.6, 0.5, 0.5, 0.6, 0.6, 0.7, 0.7, 0.6, 0.6, 0.5,
              0.5, 0.6, 0.6, 0.7, 0.7, 0.6, 0.6, 0.5, 0.5, 0.6, 0.6, 0.7};
        this->value_ = raw_value_ * weights_[y*8 +x];
    }
    std::list<std::pair<int, int>>
    Kig::compute_move(game::Board& board, bool legal) {
        auto rep = std::list<std::pair<int, int>>();

        if (legit(x_ + 1, y_) &&
            board.is_move_legal(white_, legal,x_, y_, x_ + 1, y_) &&
            board.is_adv_piece_one(x_ + 1,y_,white_))
            rep.push_front(std::pair<int, int>(x_ + 1, y_));

        if (legit(x_ - 1, y_) &&
            board.is_move_legal(white_, legal,x_, y_, x_ - 1, y_) &&
            board.is_adv_piece_one(x_ - 1,y_,white_))
            rep.push_front(std::pair<int, int>(x_ - 1, y_));
        if (legit(x_, y_ +1 ) &&
            board.is_move_legal(white_, legal,x_, y_, x_, y_ + 1) &&
            board.is_adv_piece_one(x_,y_+ 1,white_))
            rep.push_front(std::pair<int, int>(x_, y_ + 1));
        if (legit(x_, y_ -1) &&
            board.is_move_legal(white_, legal,x_, y_, x_, y_ - 1) &&
            board.is_adv_piece_one(x_,y_ - 1,white_))
            rep.push_front(std::pair<int, int>(x_, y_ - 1));

        if (legit(x_ + 1, y_ + 1) &&
            board.is_move_legal(white_, legal,x_, y_, x_ + 1, y_ + 1) &&
            board.is_adv_piece_one(x_ + 1, y_ + 1,white_))
            rep.push_front(std::pair<int, int>(x_ + 1, y_ + 1));

        if (legit(x_ + 1, y_ - 1) &&
            board.is_move_legal(white_, legal,x_, y_, x_ + 1, y_ -1 ) &&
            board.is_adv_piece_one(x_ + 1,y_ - 1,white_))
            rep.push_front(std::pair<int, int>(x_ + 1, y_ - 1));

        if (legit(x_ - 1, y_ + 1) &&
            board.is_move_legal(white_, legal,x_, y_, x_ - 1, y_ + 1) &&
            board.is_adv_piece_one(x_ - 1,y_ + 1,white_))
            rep.push_front(std::pair<int, int>(x_ - 1, y_ + 1));

        if (legit(x_ - 1, y_ - 1) &&
            board.is_move_legal(white_, legal,x_, y_, x_ - 1, y_ -1 ) &&
            board.is_adv_piece_one(x_ - 1,y_ - 1,white_))
            rep.push_front(std::pair<int, int>(x_ - 1, y_ - 1));

        if (is_started &&  board.can_big_castle(x_, y_, x_ - 2) &&
            board.is_move_legal(white_, legal,x_, y_, x_ - 1, y_) &&
            board.is_move_legal(white_, legal,x_, y_, x_ - 2, y_)
            ) {
            rep.push_front(std::pair<int, int>(x_ - 2, y_));
        }
        if (is_started &&  board.can_lil_castle(x_, y_, x_ + 2) &&
            board.is_move_legal(white_, legal,x_, y_, x_ + 1, y_) &&
            board.is_move_legal(white_, legal,x_, y_, x_ + 2, y_)) {
            rep.push_front(std::pair<int, int>(x_ + 2, y_));
        }
        return rep;
    }
} /* game */

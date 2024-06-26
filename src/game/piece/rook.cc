#include "rook.hh"
#include "piece.hh"
#include <list>
#include <utility>

namespace game {

    Rook::Rook(char piece, bool white, int x, int y, int value) {
        this->piece_ = piece;
        this->white_ = white;
        this->x_ = x;
        this->y_ = y;
        this->raw_value_ = value;
        if(!white)
            this->weights_ = {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.05,
                              1.1,1.1,1.1,1.1,1.1,1.1,1.05,0.95,
                              1.0,1.0,1.0,1.0,1.0,1.0,0.95,0.95,
                              1.0,1.0,1.0,1.0,1.0,1.0,0.95,0.95,
                              1.0,1.0,1.0,1.0,1.0,1.0,0.95,0.95,
                              1.0,1.0,1.0,1.0,1.0,1.0,0.95,0.95,
                              1.0,1.0,1.0,1.0,1.0,1.0,0.95,1.0,
                              1.0,1.0,1.05,1.05,1.0,1.0,1.0};
        else
          this->weights_ = {
              1.0,  1.0,  1.0,  1.05, 1.05, 1.0,  1.0,  1.0,  0.95, 1.0,  1.0,
              1.0,  1.0,  1.0,  1.0,  0.95, 0.95, 1.0,  1.0,  1.0,  1.0,  1.0,
              1.0,  0.95, 0.95, 1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  0.95, 0.95,
              1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  0.95, 0.95, 1.0,  1.0,  1.0,
              1.0,  1.0,  1.0,  0.95, 1.05, 1.1,  1.1,  1.1,  1.1,  1.1,  1.1,
              1.05, 1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0};
        this->value_ = raw_value_;// * weights_[y*8 +x];
    }

    std::list<std::pair<int, int>>
    Rook::compute_move(game::Board& board, bool legal) {
        auto rep = std::list<std::pair<int, int>>();

        int i = x_ + 1;
        while (legit(i,y_) && board.is_move_legal(white_, legal,x_, y_, i, y_) &&
               board.is_adv_piece(i,y_,white_)) {
            rep.push_front(std::pair<int, int>(i, y_));
            i++;
        }

        if (legit(i, y_) && board.is_move_legal(white_, legal, x_, y_, i, y_) &&
            board.is_adv_piece_capt(i, y_, white_))
            rep.push_front(std::pair<int, int>(i, y_));

        int j = y_ + 1;
        while (legit(x_,j) && board.is_move_legal(white_, legal,x_, y_, x_, j) &&
               board.is_adv_piece(x_,j,white_)) {
            rep.push_front(std::pair<int, int>(x_, j));
            j++;
        }

        if (legit(x_, j) && board.is_move_legal(white_, legal, x_, y_, x_, j) &&
            board.is_adv_piece_capt(x_, j, white_))
            rep.push_front(std::pair<int, int>(x_, j));

        i = x_ - 1;
        while (legit(i,y_) && board.is_move_legal(white_, legal,x_, y_, i, y_) &&
               board.is_adv_piece(i,y_,white_)) {
            rep.push_front(std::pair<int, int>(i, y_));
            i--;
        }

        if (legit(i, y_) && board.is_move_legal(white_, legal, x_, y_, i, y_) &&
            board.is_adv_piece_capt(i, y_, white_))
            rep.push_front(std::pair<int, int>(i, y_));

        j = y_ - 1;
        while (legit(x_,j) && board.is_move_legal(white_, legal,x_, y_, x_, j) &&
               board.is_adv_piece(x_,j,white_)) {
            rep.push_front(std::pair<int, int>(x_, j));
            j--;
        }
        if (legit(x_, j) && board.is_move_legal(white_, legal, x_, y_, x_, j) &&
            board.is_adv_piece_capt(x_, j, white_))
            rep.push_front(std::pair<int, int>(x_, j));

        return rep;
    }
} /* game */

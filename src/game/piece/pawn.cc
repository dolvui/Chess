#include "pawn.hh"
#include "piece.hh"
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
    Pawn::compute_move(game::Board& board) {
        auto rep = std::list<std::pair<int, int>>();

        if (white_) {

          if (board.is_piece_move(x_, y_ - 1, white_)) {
            rep.push_front(std::pair<int, int>(x_, y_ - 1));
            if(is_started && board.is_piece_move(x_,y_ - 2,white_))
              rep.push_front(std::pair<int, int>(x_, y_ - 2));
          }

            if(board.is_capt_piece(x_ + 1,y_ - 1,white_))
              rep.push_front(std::pair<int, int>(x_ + 1, y_ - 1));

            if(board.is_capt_piece(x_ - 1,y_ - 1,white_))
                rep.push_front(std::pair<int, int>(x_ - 1, y_ - 1));

        } else {
            if (board.is_move_legal(white_,y_*8+x_,(y_+1)*8+x_)
              && board.is_adv_piece(x_,y_ + 1,white_))
                rep.push_front(std::pair<int, int>(x_, y_ + 1));

            if(board.is_capt_piece(x_ + 1,y_ + 1,white_))
                rep.push_front(std::pair<int, int>(x_ + 1, y_ + 1));
            if(board.is_capt_piece(x_ - 1,y_ + 1,white_))
                rep.push_front(std::pair<int, int>(x_ - 1, y_ + 1));

            if(is_started && board.is_adv_piece(x_,y_ + 2,white_))
                rep.push_front(std::pair<int, int>(x_, y_ + 2));
        }
        return rep;
    }
} /* game */

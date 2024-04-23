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
    Pawn::compute_move(game::Board& board,bool legal) {
        auto rep = std::list<std::pair<int, int>>();

        if (white_) {

          if (legal && board.is_move_legal(white_,x_,y_,x_,y_ - 1)
              && board.is_piece_move(x_, y_ - 1, white_)) {
            rep.push_front(std::pair<int, int>(x_, y_ - 1));

            if(legal && board.is_move_legal(white_,x_,y_,x_,y_ - 2)
              && is_started && board.is_piece_move(x_,y_ - 2,white_))
              rep.push_front(std::pair<int, int>(x_, y_ - 2));
          }

            if(legal && board.is_move_legal(white_,x_,y_,x_ + 1,y_ - 1)
              && board.is_capt_piece(x_ + 1,y_ - 1,white_))
              rep.push_front(std::pair<int, int>(x_ + 1, y_ - 1));

            if(legal && board.is_move_legal(white_,x_,y_,x_ - 1,y_ - 1)
              && board.is_capt_piece(x_ - 1,y_ - 1,white_))
                rep.push_front(std::pair<int, int>(x_ - 1, y_ - 1));

        } else {
            if (legal && board.is_move_legal(white_,x_,y_,x_,y_ + 1)
              && board.is_adv_piece(x_,y_ + 1,white_))
                rep.push_front(std::pair<int, int>(x_, y_ + 1));

            if(legal && board.is_move_legal(white_,x_,y_,x_ + 1,y_ + 1)
              && board.is_capt_piece(x_ + 1,y_ + 1,white_))
              rep.push_front(std::pair<int, int>(x_ + 1, y_ + 1));

            if(legal && board.is_move_legal(white_,x_,y_,x_ - 1,y_ + 1)
              && board.is_capt_piece(x_ - 1,y_ + 1,white_))
                rep.push_front(std::pair<int, int>(x_ - 1, y_ + 1));

            if(legal && board.is_move_legal(white_,x_,y_,x_,y_ + 2)
              && is_started && board.is_adv_piece(x_,y_ + 2,white_))
                rep.push_front(std::pair<int, int>(x_, y_ + 2));
        }
        return rep;
    }
} /* game */

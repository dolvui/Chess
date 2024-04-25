#include "knight.hh"
#include "piece.hh"
#include <list>
#include <utility>

namespace game {

Knight::Knight(char piece, bool white, int x, int y, int value) {
    this->piece_ = piece;
    this->white_ = white;
    this->x_ = x;
    this->y_ = y;
    this->value_ = value;
}

    std::list<std::pair<int, int>>
    Knight::compute_move(game::Board& board, bool legal) {
        auto rep = std::list<std::pair<int, int>>();

        if (legit(x_ + 2, y_ + 1) &&
            board.is_move_legal(white_, legal,x_, y_, x_ + 2 , y_  + 1) &&
            board.is_adv_piece_one(x_ + 2,y_ + 1,white_))
          rep.push_front(std::pair<int, int>(x_ + 2, y_ + 1));
        if (legit(x_ + 2, y_ - 1) &&
            board.is_move_legal(white_, legal,x_, y_, x_ + 2, y_ - 1) &&
            board.is_adv_piece_one(x_ + 2,y_ - 1,white_))
            rep.push_front(std::pair<int, int>(x_ +2, y_ - 1));

        if (legit(x_ + 1, y_ -2) &&
            board.is_move_legal(white_, legal,x_, y_, x_ + 1, y_ - 2) &&
            board.is_adv_piece_one(x_ + 1,y_ - 2,white_))
          rep.push_front(std::pair<int, int>(x_ + 1, y_ - 2));
        if (legit(x_ + 1, y_ + 2) &&
            board.is_move_legal(white_, legal,x_, y_, x_ + 1, y_ + 2) &&
            board.is_adv_piece_one(x_ + 1,y_ + 2,white_))
            rep.push_front(std::pair<int, int>(x_ + 1, y_+ 2));

        if (legit(x_ - 2, y_ + 1) &&
            board.is_move_legal(white_, legal,x_, y_, x_ - 2, y_ + 1) &&
            board.is_adv_piece_one(x_ - 2 ,y_ + 1,white_))
          rep.push_front(std::pair<int, int>(x_ - 2, y_ + 1));
        if (legit(x_ - 2, y_ - 1) &&
            board.is_move_legal(white_, legal,x_, y_, x_ - 2, y_ - 1) &&
            board.is_adv_piece_one(x_ - 2 ,y_ - 1,white_))
            rep.push_front(std::pair<int, int>(x_ - 2, y_ - 1));

        if (legit(x_ - 1, y_ - 2) &&
            board.is_move_legal(white_, legal,x_, y_, x_ -1 , y_ - 2) &&
            board.is_adv_piece_one(x_ - 1,y_ - 2,white_))
          rep.push_front(std::pair<int, int>(x_ - 1, y_ - 2));
        if (legit(x_ - 1, y_ + 2) &&
            board.is_move_legal(white_, legal,x_, y_, x_ - 1, y_ + 2) &&
            board.is_adv_piece_one(x_ - 1,y_ + 2 ,white_))
            rep.push_front(std::pair<int, int>(x_ - 1, y_ + 2));

        return rep;
    }
} /* game */

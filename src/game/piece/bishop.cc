#include "bishop.hh"
#include "piece.hh"
#include <list>
#include <utility>

namespace game {

    Bishop::Bishop(char piece, bool white, int x, int y, int value) {
        this->piece_ = piece;
        this->white_ = white;
        this->x_ = x;
        this->y_ = y;
        this->value_ = value;
    }

    std::list<std::pair<int, int>>
    Bishop::compute_move(game::Board &board, bool legal) {

        auto rep = std::list<std::pair<int, int>>();

        int i = x_ + 1;
        int j = y_ + 1;
        while (legit(i,j) && board.is_adv_piece(i, j, white_)
               && board.is_move_legal(white_,legal,x_, y_, i, j)) {
            rep.push_front(std::pair<int, int>(i, j));
            i++;
            j++;
        }

        if (legit(i,j) && board.is_adv_piece_capt(i, j, white_))
            rep.push_front(std::pair<int, int>(i, j));

        i = x_ - 1;
        j = y_ - 1;
        while (legit(i,j) && board.is_move_legal(white_,legal, x_, y_, i, j) &&
               board.is_adv_piece(i,j,white_)) {
            rep.push_front(std::pair<int, int>(i, j));
            i--;
            j--;
        }
        if (legit(i,j) && board.is_adv_piece_capt(i, j, white_))
            rep.push_front(std::pair<int, int>(i, j));

        i = x_ + 1;
        j = y_ - 1;
        while (legit(i,j) && board.is_move_legal(white_, legal,x_, y_, i, j) &&
               board.is_adv_piece(i,j,white_)) {
            rep.push_front(std::pair<int, int>(i, j));
            i++;
            j--;
        }
        if (legit(i,j) && board.is_adv_piece_capt(i, j, white_))
            rep.push_front(std::pair<int, int>(i, j));

        i = x_ - 1;
        j = y_ + 1;
        while (legit(i,j) && board.is_move_legal(white_, legal,x_, y_, i, j) &&
               board.is_adv_piece(i,j,white_)) {
            rep.push_front(std::pair<int, int>(i, j));
            i--;
            j++;
        }
        if (legit(i,j) && board.is_adv_piece_capt(i, j, white_))
            rep.push_front(std::pair<int, int>(i, j));

        return rep;
    }
} /* game */

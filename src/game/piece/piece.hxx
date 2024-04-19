#pragma once
#include "piece.hh"

namespace game {
    inline char Piece::get_piece(){ return piece_;}
    inline bool Piece::is_white(){return white_;}
    inline int Piece::get_x(){return x_;}
    inline int Piece::get_y(){return y_;}
    inline int Piece::get_value() { return value_; }


    inline void Piece::set_x(int x){x_ = x;}
    inline void Piece::set_y(int y) { y_ = y; }
    inline void Piece::set_pos(int pos) {
      x_ = pos % 8;
      y_ = pos / 8;
      is_started = false;
    }
}

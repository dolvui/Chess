#include "piece.hh"

namespace game
{
    Piece::Piece(char piece, bool white, int x, int y, int value)
    : piece_(piece) , white_(white) , x_(x) , y_(y) , value_(value){}
} /* game */

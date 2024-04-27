#pragma once

#include "../piece/piece.hh"
#include <ostream>

namespace game {
    class Piece;
    class Move {
    public:
        Move(char piece_, bool white_, int start_,
             int end_, bool capt_, bool check_);
        Move(Piece* start, Piece* end,char* prom);
        Move(Piece* start , int end,char* prom);
        char piece_;
        bool white_;
        int start_;
        int end_;
        bool capt_;
        bool check_;
        std::string prom;
        //void operator<<( const Move& obj);
    };
} /* game */

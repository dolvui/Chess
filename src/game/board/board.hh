#pragma once

#include <array>
#include <memory>
#include <utility>

#include "../piece/piece.hh"
#include "../player/player.hh"

namespace game {
    class Piece;
    class Board {
    public:
        Board();
        int  move(int start,int end);
        void print_board();
        int compute_move(std::string move_not, bool white);
        int find_start(char piece, bool white, int dest);
        bool is_adv_piece(int x, int y, bool white);
        bool is_capt_piece(int i, int j, bool white);
        bool is_piece_move(int i, int j, bool white);
        bool can_castle(int x, int y, int new_x);
        int caslte(bool little, bool white);
        int promote(int start, int end, char prom);
//        void update(bool white);
        std::list<std::pair<int, int>> get_legal_moves(bool white);
    private:
        std::array<Piece *, 64> board_;
        Piece *hold_white_;
        Piece *hold_black_;
    };
} /* game */

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
        bool is_adv_piece_one(int i, int j, bool white);
        bool is_adv_piece_capt(int i, int j, bool white);
        bool can_big_castle(int x, int y, int new_x);
        bool can_lil_castle(int x, int y, int new_x);
        int caslte(bool little, bool white);
        int promote(int start, int end, char prom);
        int update(bool white);
        int is_move_legal(bool white, bool check, int x_start,
                          int y_start, int x_end,int y_end);
        std::list<std::pair<int, int>> get_legal_moves(bool white);
    private:
        std::array<Piece *, 64> board_;
        Piece *hold_white_;
        Piece *hold_black_;
    };
} /* game */

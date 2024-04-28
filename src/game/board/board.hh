#pragma once

#include <array>
#include <memory>
#include <utility>
#include <vector>

#include "move.hh"
#include "../piece/piece.hh"
#include "../player/player.hh"

namespace game {
    class Piece;
    class Move;
    class Board {
    public:
        Board();
        int  move(int start,int end,bool set);
        void print_board();
        int compute_move(std::string move_not, bool white);
        int find_start(char piece, bool white, int dest,
                       std::pair<int,int>* pair);
        bool is_adv_piece(int x, int y, bool white);
        bool is_capt_piece(int i, int j, bool white);
        bool is_piece_move(int i, int j, bool white);
        bool is_adv_piece_one(int i, int j, bool white);
        bool is_adv_piece_capt(int i, int j, bool white);
        bool can_enpassant(int i, int j, int x , int y ,bool white);
        bool can_big_castle(int x, int y, int new_x);
        bool can_lil_castle(int x, int y, int new_x);
        int caslte(bool little, bool white);
        int promote(int start, int end, char prom);
        int update(bool white);
        int is_move_legal(bool white, bool check, int x_start,
                          int y_start, int x_end,int y_end);
        std::list<std::pair<int, int>> get_legal_moves(bool white);
        std::list<std::pair<std::pair<int, int>, std::pair<int, int>>>
        get_bot_legal_moves(bool white);
        bool is_in_check(bool white);
        bool not_enough_material();
        bool fifty_rule();
        int print_moves();
        std::array<Piece *, 64> get_board_() const;
    private:
        std::array<Piece *, 64> board_;
        std::vector<game::Move> moves_;
    };
} /* game */

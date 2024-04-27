#include <algorithm>
#include <cctype>
#include <iostream>
#include <list>
#include <memory>
#include <stdexcept>
#include <utility>

#include "../piece/piece.hh"

#include "../piece/bishop.hh"
#include "../piece/kig.hh"
#include "../piece/rook.hh"
#include "../piece/queen.hh"
#include "../piece/pawn.hh"
#include "../piece/knight.hh"

#include "../player/player.hh"
#include "board.hh"
#include "move.hh"

namespace game
{
    Board::Board()
        : board_(std::array<Piece *, 64>())
    {
        auto p1 = new game::Rook('r', false, 0, 0, 5);
        board_.at(0) = p1;

        auto p2 = new game::Knight('n', false, 1, 0, 3);
        board_.at(1) = p2;

        auto p3 = new game::Bishop('b', false, 2, 0, 3);
        board_.at(2) = p3;


        auto p4 = new game::Queen('q', false, 3, 0, 9);
        board_.at(3) = p4;


        auto p5 = new game::Kig('k', false, 4, 0, 3);
        board_.at(4) = p5;

        auto p6 = new game::Bishop('b', false, 5, 0, 3);
        board_.at(5) = p6;

        auto p7 = new game::Knight('n', false, 6, 0, 3);
        board_.at(6) = p7;

        auto p8 = new game::Rook('r', false, 7, 0, 5);
        board_.at(7) = p8;

        for (int i = 0; i < 8; i++) {
            auto p_b = new game::Pawn('p', false, i, 1, 1);
            board_.at(i+8) = p_b;
        }

        for (int i = 0; i < 8; i++) {
            auto p_w = new game::Pawn('P', true, i, 6, 1);
            board_.at(i+48) = p_w;
        }


        auto pa = new game::Rook('R', true, 0, 7, 5);
        board_.at(56) = pa;

        auto pb = new game::Knight('N', true, 1, 7, 3);
        board_.at(57) = pb;

        auto pc = new game::Bishop('B', true, 2, 7, 3);
        board_.at(58) = pc;
        auto pd = new game::Queen('Q', true, 3, 7, 9);
        board_.at(59) = pd;


        auto pe = new game::Kig('K', true, 4, 7, 3);
        board_.at(60) = pe;

        auto pf = new game::Bishop('B', true, 5, 7, 3);
        board_.at(61) = pf;

        auto pg = new game::Knight('N', true, 6, 7, 3);
        board_.at(62) = pg;

        auto ph = new game::Rook('R', true, 7, 7, 5);
        board_.at(63) = ph;
    }
    void Board::print_board() {
        int c = 8;
        for (int i = 0; i < 64; i++) {
            if (i % 8 == 0) {
                std::cout << "\n" << c << ";";
                c--;
            }
            char p = ' ';
            if (board_.at(i)) {
                p = board_.at(i)->get_piece();
            }
            std::cout << "|" << p << "|";
        }
        std::cout << "\n  ";
        for (int i = 1; i <= 8; i++) {
            std::cout << "---";
        }
        std::cout << "\n  ";
        for (char i = 'a'; i <= 'h'; i++) {
            std::cout << "|" << i << "|";
        }
        std::cout << "\n";
    }

    int  Board::move(int start, int end) {
        if (start >= 64 || start < 0 || end >= 64 || end < 0) {
            std::cout << "\n This move not valid , try a other one !\n";
            return 1;
        }
        //      std::cout << "start: " << start << "end: " << end<<"\n";
        if (board_.at(end) && tolower(board_.at(end)->get_piece()) == 'k')
          throw new std::logic_error("king just wanna be eaten");

        if(board_.at(end))
          moves_.push_back(game::Move(board_.at(start),
                                      board_.at(end),nullptr));
        else
            moves_.push_back(game::Move(board_.at(start),end,nullptr));

        if (board_.at(start) && tolower(board_.at(start)->get_piece()) == 'p') {
            if (!board_.at(start)->is_white() &&
                board_.at(start)->get_y() == 6) {
              promote(start, end, 'q');
              return 0;
            }
            if (board_.at(start)->is_white() && board_.at(start)->get_y() == 1) {
              promote(start, end, 'Q');
                return 0;
            }
            // std::cout << "s_y: " << start % 8 << "e_y: " << end % 8
            //           << "end_case: " << !board_.at(end) <<
            //     "rem pos: " <<(end % 8)*8 +  start / 8 << "\n";
            if (start % 8 != end % 8 && !board_.at(end)) {
//                std::cout << "En passant !\n";
                board_.at( (start / 8)*8 +  end % 8 ) = nullptr;
            }
        }

        board_.at(end) = board_.at(start);
        board_.at(start) = nullptr;
        if (board_.at(end)) {
            board_.at(end)->set_pos(end);
            board_.at(end)->has_moved();
        }

        if (board_.at(end) && tolower(board_.at(end)->get_piece()) == 'k' &&
            abs(end - start) == 2) {
            //std::cout << abs(end - start) << "\n";
            if (end - start < 0) {
                move(end - 2 , end + 1);
                //std::cout << "a:" << end -2 << "b: " << end + 1 << "\n";
            }else {
                move(end + 1, start + 1);
            }
        }
        return 0;
    }

    /*
      | Little | white | ret
      |   0    |  0    |  0
      |   0    |  1    |  1
      |   1    |  0    |  0
      |   1    |  1    |  1 really xd ???
    */
    int Board::caslte(bool little, bool white) {
        int start = white ? 60 : 4;
        if(little)
            return move(start, start + 2);
        return move(start , start  - 2);
    }

    int convert(char l, char num) {
        // std::cout << "recieve pos: " << l << num << " or " <<
        //     8 - (num - '0') << "," << (l - 'a')<< "\n";
        return (8-(num - '0')) * 8 + (l - 'a');
    }

    int Board::promote(int start, int end, char prom) {
        if ( (end < 0 && end  > 7) || (end < 56 && end > 64) ) {
            std::cout << " The Promotion is not legit!\n";
            return 1;
        }

        switch (prom) {
        case 'N':
            board_.at(end) = new game::Knight('N', true,
                                              board_.at(start)->get_x(),
                                              board_.at(start)->get_y(),3);
            break;
        case 'B':
            board_.at(end) = new game::Bishop('B', true,
                                              board_.at(start)->get_x(),
                                              board_.at(start)->get_y(),3);
            break;
        case 'Q':
            board_.at(end) = new game::Queen('Q', true,
                                             board_.at(start)->get_x(),
                                             board_.at(start)->get_y(),9);
            break;
        case 'R':
            board_.at(end) = new game::Rook('R', true,
                                            board_.at(start)->get_x(),
                                            board_.at(start)->get_y(),5);
            break;
        case 'n':
            board_.at(end) = new game::Knight('n', false,
                                              board_.at(start)->get_x(),
                                              board_.at(start)->get_y(),3);
            break;
        case 'b':
            board_.at(end) = new game::Bishop('b', false,
                                              board_.at(start)->get_x(),
                                              board_.at(start)->get_y(),3);
            break;
        case 'q':
            board_.at(end) = new game::Queen('q', false,
                                             board_.at(start)->get_x(),
                                             board_.at(start)->get_y(),9);
            break;
        case 'r':
            board_.at(end) = new game::Rook('r', false,
                                            board_.at(start)->get_x(),
                                            board_.at(start)->get_y(),5);
            break;
        default:
            return 1;
        }
        // board_.at(start);
        board_.at(start) = nullptr;
        board_.at(end)->set_pos(end);
        return 0;
    }
    std::pair<int, int>* get_spec(char spec) {
      if (std::isdigit(spec)) {
          return new std::pair<int,int>(-1,spec - '0');
      }
      return new std::pair<int,int>(-1,spec - 'a');
    }
    int Board::compute_move(std::string move_not,bool white) {
        std::string piece;
        std::string destination;

        if (move_not.compare("O-O") == 0 || move_not.compare("0-0") == 0)
            return caslte(true,white);
        if (move_not.compare("O-O-O") == 0 || move_not.compare("0-0-0") == 0)
            return caslte(false,white);
        std::pair<int,int>* pair = nullptr;
        if (islower(move_not[0])) {
            piece = "P";
            destination = move_not.substr(0, 2);
            if (move_not.length() == 4 && move_not[2] == '=') {
                int dest = convert(destination[0],destination[1]);
                int start = find_start(piece[0], white, dest,nullptr);
                return promote(start,dest,move_not[3]);
            }
            else if(move_not.length() == 3){ // cd5
                char spec = move_not[0];
                pair = get_spec(spec);
                //piece = move_not.substr(0, 1);
                destination = move_not.substr(1, 2);
                int dest = convert(destination[0],destination[1]);
                int start = find_start(piece[0], white, dest,pair);
                return move(start,dest);
            }
        } else {
          if (move_not.size() == 4) { // Reb6
            char spec = move_not[1];
            pair = get_spec(spec);
            piece = move_not.substr(0, 1);
            destination = move_not.substr(2, 3);
          }
          else {
                piece = move_not.substr(0, 1);
                destination = move_not.substr(1, 2);
            }
            // piece = move_not.substr(0, 1);
            // destination = move_not.substr(1, 2);
        }
        int dest = convert(destination[0],destination[1]);
        int start = find_start(piece[0], white, dest,pair);
        return move(start,dest);
    }
    int Board::find_start(char piece, bool white,
                          int dest,std::pair<int,int>* pair) {
        if (!white)
            piece = std::tolower(piece);
        for (int i = 0 ; i < 64 ; i++) {
            if (board_.at(i) && board_.at(i)->get_piece() == piece) {
                auto l = board_.at(i)->compute_move(*this,true);
                for (auto m : l) {
                  if (m.second * 8 + m.first == dest) {
                      //   std::cout << pair->first << " = " << m.first <<
                      //       " and "<<pair->second << " = "<<m.second << "\n";
                      if (!pair)
                          return i;
                      else if (pair->first == i/8 || pair->second == i%8)
                          return i;
                  }
                }
            }
        }
        return -1;
    }

    std::list<std::pair<int, int>> Board::get_legal_moves(bool white) {
        auto rep = std::list<std::pair<int, int>>();
        for (int i = 0 ; i < 64 ; i++) {
            if (board_.at(i)) {
                if (!(board_.at(i)->is_white() ^ white)) {
                    auto l = board_.at(i)->compute_move(*this,true);
                    // std::cout << "for the "
                    //           << board_.at(i)->get_piece()
                    //           << " in " << i << " :\n";
                    for (auto m : l) {
                        // std::cout << board_.at(i)->get_x()
                        //           << ","
                        //           << board_.at(i)->get_y()
                        //      <<" to " << m.first << "," << m.second << "\n";
                    }
                    rep.merge(l);
                };
            }
        }
        return rep;
    }

    std::list<std::pair<std::pair<int, int>, std::pair<int, int>>>
    Board::get_bot_legal_moves(bool white) {
        auto rep = std::list < std::pair < std::pair<int, int>,
                                           std::pair<int, int>>>();
        for (int i = 0 ; i < 64 ; i++) {
            if (board_.at(i)) {
                if (!(board_.at(i)->is_white() ^ white)) {
                  auto l = board_.at(i)->compute_move(*this, true);
                  // std::cout << "for the "
                  //             << board_.at(i)->get_piece()
                  //             << " in " << i << " :\n";
                  for (auto m : l) {
                      // std::cout << board_.at(i)->get_x()
                      //             << ","
                      //             << board_.at(i)->get_y()
                      //        <<" to " << m.first << "," << m.second << "\n";
                        auto p_start = std::pair<int, int>
                            (board_.at(i)->get_x(),board_.at(i)->get_y());
                        auto p_end = std::pair<int, int>(m.first,m.second);
                        auto p = std::pair<std::pair<int, int>,
                                           std::pair<int, int>>(p_start,p_end);
                        rep.push_front(p);
                    }
                };
            }
        }
        return rep;
    }

    int Board::update(bool white) {
        return 0;
    }

    bool Board::is_in_check(bool white) {
        for (int i = 0 ; i < 64 ; i++) {
            if (board_.at(i)
                && (board_.at(i)->is_white() ^ white)) {
                auto l = board_.at(i)->compute_move(*this, false);
                for (auto move : l) {
                    int pos = move.second * 8 + move.first;
                    if (board_.at(pos) &&
                        tolower(board_.at(pos)->get_piece()) == 'k') {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool Board::not_enough_material() {
      for (int i = 0; i < 64; i++) {
          auto p = board_.at(i);
          if (p && (tolower(p->get_piece()) == 'p'
                    || tolower(p->get_piece()) == 'r'
                    || tolower(p->get_piece()) == 'q'))
            return false;

      }
      return true;
    }

    int Board::is_move_legal(bool white, bool check, int x_start,
                                 int y_start, int x_end, int y_end)
        {
            if (check == false)
                return true;
            int start = y_start * 8 + x_start;
            int dest = y_end * 8 + x_end;
            if (x_start < 0 || x_start > 7 || x_end < 0 || x_end > 7 ||
                y_start < 0 || y_start > 7 || y_end < 0 || y_end > 7 ||
                start < 0 || start >= 64 || dest < 0 || dest >= 64)
                return false;
            auto piece_start = board_.at(start);
            auto piece_dest = board_.at(dest);

            if (board_.at(dest) && !(board_.at(dest)->is_white() ^ white))
                return false;

            board_.at(start) = nullptr;
            board_.at(dest) = piece_start;
            for (int i = 0 ; i < 64 ; i++) {
                if (board_.at(i)
                    && (board_.at(i)->is_white() ^ white)) {
                    auto l = board_.at(i)->compute_move(*this, false);
                    for (auto move : l) {
                        int pos = move.second * 8 + move.first;
                        if (board_.at(pos) &&
                            tolower(board_.at(pos)->get_piece()) == 'k') {
                            board_.at(start) = piece_start;
                            board_.at(dest) = piece_dest;
                            return false;
                        }
                    }
                }
            }

            board_.at(start) = piece_start;
            board_.at(dest) = piece_dest;
            return true;
        }

        bool Board::is_adv_piece(int i, int j, bool white) {
            int pos = (j * 8 + i);
            auto p = board_.at(pos);
            return !p;
            if(p)
                return (p->is_white() ^ white);
            return true;
        }

        bool Board::is_adv_piece_capt(int i, int j, bool white) {
            int pos = (j * 8 + i);
            auto p = board_.at(pos);
            if(p)
                return (p->is_white() ^ white);
            return false;
        }

        bool Board::is_adv_piece_one(int i, int j, bool white) {
            int pos = (j * 8 + i);;

            auto p =  board_.at(pos);
            if(p)
                return (p->is_white() ^ white);
            return true;
        }

        bool Board::is_capt_piece(int i, int j, bool white) {
            int pos = (j * 8 + i);
            if (pos < 0 || pos >= 64)
                return false;
            auto p = board_.at(pos);
            return p && p->is_white() ^ white;
        }
        bool Board::is_piece_move(int i, int j, bool white) {
            int pos = (j * 8 + i);
            auto p = board_.at(pos);
            return !p;

        }
        bool Board::can_big_castle(int x, int y, int new_x) {
            int start = y * 8 + x;
            int end = y * 8 + new_x;

            if (board_.at(start - 1) || board_.at(start - 2) ||
                board_.at(start - 3) ||
                (board_.at(start - 4) && !board_.at(start - 4 )->get_started())){
                return false;
            }
            //std::cout << "can big !!!!\n";
            return true;
        }
        bool Board::can_lil_castle(int x, int y, int new_x) {
            int start = y * 8 + x;
            int end = y * 8 + new_x;

            if (board_.at(start + 1) || board_.at(start + 2) ||
                (board_.at(start + 3) && !board_.at(start + 3)->get_started())){
                return false;
            }
            //std::cout << "can little !!!!\n";
            return true;
        }
    bool Board::can_enpassant(int i, int j, int x, int y, bool white) {
        if (moves_.size() == 0)
            return false;
        auto prev = moves_.back();
        if (!(tolower(prev.piece_) == 'p' && prev.white_ ^ white))
          return false;
        if (abs(prev.end_ / 8 - prev.start_ / 8) != 2)
          return false;
        if (j != prev.end_ / 8)
          return false;
        if (x != prev.end_ % 8)
            return false;
        return true;
    }
    std::string convert_int_not(int pos) {
        char x = pos % 8 + 'a';
        char y = pos / 8 + '0';
        return std::string(1,x)+y;
    }
    int Board::print_moves() {
        std::cout << "\nList of moves: \n";
        for (Move obj : moves_) {
          std::string capt = ((obj.capt_) ? "x" : "");
          char p = std::toupper(obj.piece_);
            std::cout << p << convert_int_not(obj.start_) <<
                capt << convert_int_not(obj.end_) << " " << obj.prom;
        }
        return moves_.size();
    }

    bool Board::fifty_rule() {
        int f = 0;
        for (auto it = moves_.cend(); it != moves_.cbegin() && f != 100; it--) {
          if (it->capt_ || tolower(it->piece_) == 'p') {
              //   std::cout << f;
              return false;
          }
            f++;
        }
        return f == 100;
    }
} /* game */

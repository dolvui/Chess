#include <algorithm>
#include <cctype>
#include <iostream>
#include <list>
#include <memory>
#include <utility>
#include "../piece/piece.hh"

#include "../piece/bishop.hh"
#include "../piece/kig.hh"
#include "../piece/rook.hh"
#include "../piece/queen.hh"
#include "../piece/pawn.hh"
#include "../piece/knight.hh"
#include "../piece/hold.hh"

#include "../player/player.hh"
#include "board.hh"

namespace game
{
Board::Board()
    : board_(std::array<Piece *, 64>()),
      hold_white_(new game::Hold('H', true, -1, -1, -1)),
      hold_black_(new game::Hold('h', false, -1, -1, -2))
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
    }
    int  Board::move(int start, int end) {
      if (start >= 64 || start < 0 || end >= 64 || end < 0) {
          std::cout << "move not legit sorry";
          return 1;
      }
      board_.at(end) = board_.at(start);
      board_.at(start) = nullptr;
      board_.at(end)->set_pos(end);

      if (tolower(board_.at(end)->get_piece()) == 'k' &&
          abs(end - start) == 2) {
        if (abs(end - start) < 0) {
            move(end - 2 , start - 1);
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
        if (start >= 64 || start < 0 || end >= 64 || end < 0 || end < 56 ) {
            std::cout << "move not legit sorry";
            return 1;
        }

        switch (prom) {
        case 'N':
          board_.at(end) = new game::Knight('N', board_.at(start)->is_white(),
                                            board_.at(start)->get_x(),
                                            board_.at(start)->get_y(),3);
            break;
        case 'B':
            board_.at(end) = new game::Bishop('B', board_.at(start)->is_white(),
                                            board_.at(start)->get_x(),
                                            board_.at(start)->get_y(),3);
            break;
        case 'Q':
            board_.at(end) = new game::Queen('Q', board_.at(start)->is_white(),
                                            board_.at(start)->get_x(),
                                            board_.at(start)->get_y(),9);
            break;
        case 'R':
            board_.at(end) = new game::Rook('R', board_.at(start)->is_white(),
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
    int Board::compute_move(std::string move_not,bool white) {
       std::string piece;
       std::string destination;

       if (move_not.compare("O-O") == 0 || move_not.compare("0-0") == 0)
           return caslte(true,white);
       if (move_not.compare("O-O-O") == 0 || move_not.compare("0-0-0") == 0)
         return caslte(false,white);

       if (islower(move_not[0])) {
           piece = "P";
           destination = move_not.substr(0, 2);
           if (move_not.length() == 4) {
               int dest = convert(destination[0],destination[1]);
               int start = find_start(piece[0], white, dest);
               return promote(start,dest,move_not[3]);
           }
       } else {
           piece = move_not.substr(0, 1);
           destination = move_not.substr(1, 2);
       }
       int dest = convert(destination[0],destination[1]);
       int start = find_start(piece[0], white, dest);
//       std::cout << "start: " << start << " and dest: " << dest << "\n";
       return move(start,dest);
    }
    int Board::find_start(char piece, bool white, int dest) {
        if (!white)
            piece = std::tolower(piece);
        for (int i = 0 ; i < 64 ; i++) {
            if (board_.at(i) && board_.at(i)->get_piece() == piece) {
            auto l = board_.at(i)->compute_move(*this);
            for (auto m : l) {
              // std::cout << "from " << i
              //           << " to "
              //           << m.second*8 + m.first << "\n";
              if (m.second*8 + m.first == dest)
                  return i;
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
              auto l = board_.at(i)->compute_move(*this);
              std::cout << "for the "
                        << board_.at(i)->get_piece()
                        << " in " << i << " :\n";
              for (auto m : l) {
                std::cout << board_.at(i)->get_x()
                          << ","
                          << board_.at(i)->get_y()
                            <<" to " << m.first << "," << m.second << "\n";
              }
              rep.merge(l);
            };
        }
      }
      return rep;
    }

//     void Board::update(bool white) {
//         for (int i = 0 ; i < 64 ; i++) {
//             if (board_.at(i) && board_.at(i)->get_value() > 0) {
//                 auto l = board_.at(i)->compute_move(*this);
//                 for (auto move : l) {
//                     if(white && !board_.at(move.second * 8 + move.first))
//                       board_.at(move.second * 8 + move.first) = hold_white_;
//                     if(!white && !board_.at(move.second * 8 + move.first))
//                       board_.at(move.second * 8 + move.first) = hold_black_;
// //                    std::cout << "at" <<
//                 }
//             }

//         }
//     }

    bool Board::is_adv_piece(int i, int j, bool white) {
      int pos = (j * 8 + i);
        if (pos < 0 || pos >= 64)
          return false;

      auto p = board_.at(pos);
      if(p)
        return p->is_white() ^ white;
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
        if (pos < 0 || pos >= 64)
            return false;
      auto p = board_.at(pos);
      return !p;

    }
    bool Board::can_castle(int x, int y, int new_x) {
      int start = y * 8 + x;
      int end = y * 8 + new_x;
      int a = 1;
      if (start > end) {
          start = start ^ end;
          end = start ^ end;
          start = start ^ end;
          a = -1;
      }
      for (int i = start + 1; i < end; i++) {
        if (board_.at(i))
            return false;
      }
      if(new_x < 0)
        return board_.at(y * 8 + new_x - 1) &&
            board_.at(y * 8 + new_x - 1)->get_started();
      return board_.at(y * 8 + new_x + 1) &&
            board_.at(y * 8 + new_x + 1)->get_started();
    }
} /* game */

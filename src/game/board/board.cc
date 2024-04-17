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

#include "../player/player.hh"
#include "board.hh"

namespace game
{
Board::Board() : board_(std::array<Piece *, 64>()) {
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
    void Board::move(int start, int end) {
      board_.at(end) = board_.at(start);
      board_.at(start) = nullptr;
      board_.at(end)->set_pos(end);
   }


   int convert(char l, char num) {
       // std::cout << "recieve pos: " << l << num << " or " <<
       //     8 - (num - '0') << "," << (l - 'a')<< "\n";
       return (8-(num - '0')) * 8 + (l - 'a');
    }

    int Board::compute_move(std::string move_not,bool white) {
       std::string piece;
       std::string destination;

       if (move_not.compare("O-O") == 0)
         return 1;
       if (move_not.compare("O-O-O") == 0)
         return 1;

       if (islower(move_not[0])) {
           piece = "P";
           destination = move_not.substr(0, 2);
       } else {
           piece = move_not.substr(0, 1);
           destination = move_not.substr(1, 2);
       }
       int dest = convert(destination[0],destination[1]);
       int start = find_start(piece[0], white, dest);
//       std::cout << "start: " << start << " and dest: " << dest << "\n";
       move(start,dest);
       return 0;
    }
    int Board::find_start(char piece, bool white, int dest) {
        if (!white)
            piece = std::tolower(piece);
        for (int i = 0 ; i < 64 ; i++) {
            if (board_.at(i) && board_.at(i)->get_piece() == piece) {
            auto l = board_.at(i)->compute_move(board_);
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
              auto l = board_.at(i)->compute_move(board_);
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
    game::Piece *Board::get_piece(int i) { return board_.at(i); }
} /* game */

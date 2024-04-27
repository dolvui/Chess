#include "move.hh"
#include <cctype>
#include <iostream>
#include <string>
#include "../piece/piece.hh"

namespace game {
Move::Move(char piece, bool white, int start, int end, bool capt, bool check)
    : piece_(piece), white_(white), start_(start), end_(end), capt_(capt),
      check_(check) {}


    Move::Move(Piece* start, Piece* end,char* prom) {
      this->piece_ = tolower(start->get_piece());
      this->white_ = start->is_white();
      this->start_ = start->get_y() * 8 + start->get_x();
      this->end_ = end->get_y() * 8 + end->get_x();
      this->capt_ = true;
      this->check_ = false;
      if (prom)
          this->prom = "=" + std::to_string(*prom);
      else
            this->prom = "";
    }
    Move::Move(Piece* start, int end, char* prom) {
        this->piece_ = tolower(start->get_piece());
        this->white_ = start->is_white();
        this->start_ = start->get_y() * 8 + start->get_x();
        this->end_ = end;
        this->capt_ = false;
        this->check_ = false;
        if (prom)
          this->prom = "=" + std::to_string(*prom);
        else
            this->prom = "";
    }
    // std::string convert_int_not(int pos) {
    //   char x = pos % 8 + 'a';
    //   char y = pos / 8 + '0';
    //   return std::string(1,x)+y;
    // }
    // void Move::operator<<(const Move &obj) {
    //   std::string s =
    //       ((obj.piece_ != 'p') ? std::to_string(toupper(obj.piece_)) : "");
    //   std::string capt =
    //       ((obj.capt_) ? "x" : "");
    //   std::cout << s << convert_int_not(obj.start_) <<
    //       capt << convert_int_not(obj.end_);
    // }
} /* game */

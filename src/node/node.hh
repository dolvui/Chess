#pragma once
#include "../game/board/board.hh"

#include <vector>
namespace game {
    class Node {
    public:
      Node(Board &board, float heur, bool white);
        void add_child(Node* node);
        float get_value();
        Board& get_board();
        std::vector<Node *> get_childs();
        void set_minmax_value(float val);
        float get_minmax_value();
        int get_index_max_val();
        int get_index_min_val();
    private:
        float value_;
        std::vector<Node*> nodes_;
        Board &board_;
        bool white_;
        float minmax_val;
    };
} // namespace game

#include "node.hxx"

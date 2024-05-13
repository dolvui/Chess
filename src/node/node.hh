#pragma once
#include "../game/board/board.hh"

#include <vector>
namespace game {
    class Node {
    public:
      Node(float heur, bool white);
        void add_child(Node* node);
        float get_value();
        std::pair<std::pair<int, int>, std::pair<int, int>> get_move();
        std::vector<Node *> get_childs();
        void set_minmax_value(float val);
        float get_minmax_value();
        int get_index_max_val();
        int get_index_min_val();
    private:
        float value_;
        std::vector<Node*> nodes_;
        bool white_;
        float minmax_val;
        std::pair<std::pair<int, int>, std::pair<int, int>> move_;
    };
} // namespace game

#include "node.hxx"

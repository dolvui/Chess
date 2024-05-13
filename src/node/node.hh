#pragma once
#include "../game/board/board.hh"
#include "../game/board/move.hh"

#include <vector>
namespace game {
    class Node {
    public:
        Node(float heur, bool white,Move* move);
        void add_child(Node* node);
        float get_value();
        Move* get_move();
        std::vector<Node *> get_childs();
        void set_minmax_value(float val);
        float get_minmax_value();
        Move* get_index_best_val();
    private:
        float value_;
        std::vector<Node*> nodes_;
        bool white_;
        float minmax_val;
        Move* move_;
        //std::pair<std::pair<int, int>, std::pair<int, int>> move_;
    };
} // namespace game

#include "node.hxx"

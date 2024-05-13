#pragma once
#include "node.hh"

namespace game {
    inline float Node::get_value() { return value_; }
    inline std::vector<Node *> Node::get_childs() { return nodes_; }
    inline std::pair<std::pair<int, int>, std::pair<int, int>>
    Node::get_move() { return move_; }
    inline float Node::get_minmax_value() {return minmax_val;}
    inline void Node::set_minmax_value(float val){ minmax_val = val;};
}

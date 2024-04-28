#pragma once
#include "node.hh"

namespace game {
    inline float Node::get_value() { return value_; }
    inline std::vector<Node *> Node::get_childs() { return nodes_; }
    inline Board &Node::get_board() { return board_; }
    inline float Node::get_minmax_value() {return minmax_val;}
    inline void Node::set_minmax_value(float val){ minmax_val = val;};
}

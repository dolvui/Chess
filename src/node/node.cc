#include "node.hh"
#include "../game/board/move.hh"

namespace game {
    Node::Node(float heur, bool white,Move* move)
        : value_(heur), white_(white),move_(move),
          nodes_(std::vector<Node *>()){};

    void Node::add_child(Node *node) { nodes_.push_back(node); }

    Move* Node::get_index_best_val() {
        float best = nodes_[0]->get_minmax_value();
        Move* m = nodes_[0]->get_move();
        for (int i = 0; i < nodes_.size(); i++) {
          if (nodes_[i]->get_minmax_value() > best) {
                best = nodes_[i]->get_minmax_value();
                m = nodes_[i]->get_move();
            }
        }
        return m;
    }
}

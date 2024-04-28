#include "node.hh"

namespace game {
    Node::Node(Board &board, float heur, bool white)
        : board_(board), value_(heur), white_(white),
          nodes_(std::vector<Node *>()){};

    void Node::add_child(Node *node) { nodes_.push_back(node); }

    int Node::get_index_max_val() {
        int m = 0;
        float max = nodes_[0]->get_minmax_value();
        for (int i = 0; i < nodes_.size(); i++) {
            if (nodes_[i]->get_minmax_value() > max) {
                max = nodes_[i]->get_minmax_value();
                m = i;
            }
        }
        return m;
    }
    int Node::get_index_min_val() {
        int m = 0;
        float min = nodes_[0]->get_minmax_value();
        for (int i = 0; i < nodes_.size(); i++) {
            if (nodes_[i]->get_minmax_value()< min) {
                min = nodes_[i]->get_minmax_value();
                m = i;
            }
        }
        return m;
    }
}

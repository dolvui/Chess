#pragma once

#include <vector>
#include <string>
#include "../game/player/player.hh"
#include "../game/board/board.hh"
#include "../node/node.hh"

namespace game
{
    class Bot : public Player{
    public:
        Bot(std::string name,bool white);
        bool compute_move(Board &board) override;
        float evaluate_board(Board &board,bool turn);
        bool compute_heuristic(Board &board, bool white);
        bool minmax(Board &board);
        void set_compute(int c);
        void construct_tree(Node &node, int depth, bool white, Board &board);
        float compute_alphabeta_test(Node *node,int depth,Board board,
                                     bool turn,float alpha,float beta);
      private:
        int compute_ = 0;
    //     std::string name_;
    //     bool white_;
};
} /* game */

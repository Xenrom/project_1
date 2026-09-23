#pragma once
#include <iostream>
#include <vector>
#include "../input/record_moves.h"

namespace robot{
    class Robot{
        private:
            History::linkList history;
            History::linkNode currentNode;
            std::vector<int> position;

        public:
            Robot(int x, int y){
                position = {x, y};
                currentNode.setNode(x, y);
            }

            std::vector<bool> scanSurrounding(std::vector<std::vector<int>>& surrounding);
            void move();
            void retraceMove();
            void decideMove(std::vector<std::vector<int>>& surrounding);
            void record_move();
            
    };
}
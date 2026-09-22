#pragma once
#include <iostream>
#include <vector>

namespace robot{
    class Robot{
        private:

        public:
            std::vector<int> position {1, 1};

            void moveLeft();
            void moveRight();
            void moveUp();
            void moveDown();
            
    };
}
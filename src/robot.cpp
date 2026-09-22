#include <iostream>
#include <vector>
#include "../input/robot.h"

namespace robot{
    
    void Robot::moveLeft(){
        position[1] = position[1] - 1;
    };

    void Robot::moveRight(){
        position[1] = position[1] + 1;
    };

    void Robot::moveUp(){
        position[0] = position[0] - 1;
    };

    void Robot::moveDown(){
        position[0] = position[0] + 1;
    };
}
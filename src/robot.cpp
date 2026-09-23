#include <iostream>
#include <vector>
#include "../input/robot.h"

namespace robot{
    
    std::vector<bool> Robot::scanSurrounding(std::vector<std::vector<int>>& surrounding){
        int row = position[0];
        int column = position[1];

        bool up, down, left, right = {true};
        if(row - 1 < 0 || surrounding[row - 1][column] == 1){
            up = false;
        }
        if(row + 1 > static_cast<int>(surrounding.size()) || surrounding[row + 1][column] == 1){
            down = false;
        }
        if(column - 1 < 0 || surrounding[row][column - 1] == 1){
            left = false;
        }
        if(column + 1 > static_cast<int>(surrounding[0].size()) || surrounding[row][column + 1] == 1){
            right = false;
        }

        std::vector<int> node {currentNode.getPosition()};
        
        if(row-1 == node[0] && column == node[1]){
            up = false;
        }
        else if(row+1 == node[0] && column == node[1]){
            down = false;
        }
        else if (row == node[0] && column-1 == node[1]){
            left = false;
        }
        else if (row-1 == node[0] && column+1 == node[1]){
            right = false;
        }

        if(up || left || down || right){

        }
        return {up, left, down, right};
    };

    void Robot::move(){

    }
   
    void Robot::decideMove(std::vector<std::vector<int>>& surrounding){
        //{up, left, down, right}
        std::vector<bool> choices {Robot::scanSurrounding(surrounding)};

        std::vector<int> positiob {currentNode.getPosition()};
        int row = position[0];
        int column = position[1];

        if(choices[0]){
            history.createNode(row -1, column, &currentNode);
        }
        if(choices[1]){
            history.createNode(row, column - 1, &currentNode);
        }
        if(choices[2]){
            history.createNode(row + 1, column, &currentNode);
        }
        if(choices[3]){
            history.createNode(row, column + 1, &currentNode);
        }


    }

    void Robot::retraceMove(){
        bool state {true};
        do{
            History::linkNode* tempNode {currentNode.getDereference()};
            if(tempNode->getRefenceSize() > 1){
                state = false;
                currentNode = {*tempNode};
                break;

            };
        }while (state);
    };
}
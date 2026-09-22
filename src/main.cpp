#include <iostream>
#include "../input/maze.h"
#include "../input/robot.h"
#include <vector>
#include <string>

// Pass vectors by const reference to avoid copying the entire grid
void printMaze(const std::vector<std::vector<int>>& M);
bool checkMove(const std::vector<std::vector<int>>& M, const std::vector<int>& pos);

int main() {
    std::vector<std::vector<int>> Maze = maze::Maze;
    robot::Robot rob;

    char move;
    do {
        // Sets position value (ASCII 82 for 'R')
        
        Maze[rob.position[0]][rob.position[1]] = 'R'; 
        
        printMaze(Maze);
        std::cout << "Press 'w'-up: 'a'-left: 's'-down: 'd'-right: 'f'-stop: ";
        std::cin >> move;
        std::cin.ignore();

        int row = rob.position[0];
        int col = rob.position[1];

        switch (move) {
            case 'w': // Up -> Row - 1
                if (checkMove(Maze, {row - 1, col})) {
                    std::cout<<"you moved up" << std::endl;
                    rob.moveUp();
                }
                break;
            case 'a': // Left -> Col - 1
                if (checkMove(Maze, {row, col - 1})) {
                    std::cout<<"you moved left" << std::endl;
                    rob.moveLeft();
                }
                break;
            case 's': // Down -> Row + 1
                if (checkMove(Maze, {row + 1, col})) {
                    std::cout<<"you moved down" << std::endl;
                    rob.moveDown();
                }
                break;
            case 'd': // Right -> Col + 1
                if (checkMove(Maze, {row, col + 1})) {
                    std::cout<<"you moved right" << std::endl;
                    rob.moveRight();
                }
                break;
        }

        Maze[row][col] = {0};

    } while (move != 'f');
    
    return 0;
}

void printMaze(const std::vector<std::vector<int>>& M) {
    for (size_t x = 0; x < M.size(); x++) {
        for (size_t y = 0; y < M[x].size(); y++) {
            // Print 'R' if cell value is ASCII 82, otherwise print numeric value
            if (M[x][y] == 'R') {
                std::cout << "R ";
            } else {
                std::cout << M[x][y] << " ";
            }
        }
        std::cout << std::endl;
    }
}

bool checkMove(const std::vector<std::vector<int>>& M, const std::vector<int>& pos) {
    int row = pos[0];
    int col = pos[1];

    // 1. Check array bounds first to prevent crashing
    if (row < 0 || row >= static_cast<int>(M.size())) {
        std::cout<<"out of bounds" << std::endl;
        return false;
    }
    if (col < 0 || col >= static_cast<int>(M[0].size())) {
        std::cout<<"out of bounds" << std::endl;
        return false;
    }

    // 2. Check for wall collision
    if (M[row][col] == 1) {
        std::cout<<"cannot move because of wall" << std::endl;
        return false;
    }

    return true;
}
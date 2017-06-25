//CodeU:
//
//  Created by Julia Semavina on 15.06.2017
//
//  problem specification:
//      You are given a 2-dimensional map of tiles. Each tile is either land or water.
//      You have to write a function that counts the number of islands.
//
//  comments:
//      DFS
//


#include <iostream>
#include <vector>


void DFS(int x, int y, int IslandSize, std::vector<std::vector<bool>> &Island,
         std::vector<std::vector<bool>> &Visited) {
    Visited[y][x] = true;
    if (x + 1 < IslandSize && Island[y][x + 1] && !Visited[y][x + 1]) { // right
        DFS(x + 1, y, IslandSize, Island, Visited);
    }
    if (y + 1 < IslandSize && Island[y + 1][x] && !Visited[y + 1][x]) { // down
        DFS(x, y + 1, IslandSize, Island, Visited);
    }
    if (x - 1 > -1 && Island[y][x - 1] && !Visited[y][x - 1]) { // left
        DFS(x - 1, y, IslandSize, Island, Visited);
    }
    if (y - 1 > -1 && Island[y - 1][x] && !Visited[y - 1][x]) { // up
        DFS(x, y - 1, IslandSize, Island, Visited);
    }
}


int main() {
    std::cout << "Enter the size of the island:" << std::endl;
    int IslandSize;
    std::cin >> IslandSize;
    std::vector<std::vector<bool>> Island (IslandSize);
    std::vector<std::vector<bool>> Visited (IslandSize);
    char input_variable;
    std::cout << "Enter the island" << std::endl;
    for (int i = 0; i < IslandSize; ++i) {
        for (int j = 0; j < IslandSize; ++j) {
            std::cin >> input_variable;
            switch (input_variable) {
                case 'T':
                    Island[i].push_back(true);
                    Visited[i].push_back(false);
                    break;
                case 'F':
                    Island[i].push_back(false);
                    Visited[i].push_back(false);
                    break;
                default:
                    std::cout << "Not valid input" << std::endl;
                    return 0;
            }
        }
    }
    int NumberOfIslands = 0;
    for (int i = 0; i < IslandSize; ++i) {
        for (int j = 0; j < IslandSize; ++j) {
            if (Island[i][j] && !Visited[i][j]) {
                ++NumberOfIslands;
                DFS(j, i, IslandSize, Island, Visited);
            }
        }
    }
    std::cout << NumberOfIslands << std::endl;
    return 0;
}

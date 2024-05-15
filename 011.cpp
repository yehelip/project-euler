#include <iostream>
#include <vector>
#include <algorithm>

const int SIZE = 20;

int main() {
    // Taking input for the 20x20 grid
    int grid[SIZE][SIZE];
    std::cout << "Enter the elements of the 20x20 grid:" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cin >> grid[i][j];
        }
    }

    int maxProduct = 0;

    // Check horizontally
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j <= SIZE - 4; ++j) {
            int product = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
            maxProduct = std::max(maxProduct, product);
        }
    }

    // Check vertically
    for (int i = 0; i <= SIZE - 4; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int product = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];
            maxProduct = std::max(maxProduct, product);
        }
    }

    // Check diagonally (top-left to bottom-right)
    for (int i = 0; i <= SIZE - 4; ++i) {
        for (int j = 0; j <= SIZE - 4; ++j) {
            int product = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
            maxProduct = std::max(maxProduct, product);
        }
    }

    // Check diagonally (top-right to bottom-left)
    for (int i = 0; i <= SIZE - 4; ++i) {
        for (int j = 3; j < SIZE; ++j) {
            int product = grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3];
            maxProduct = std::max(maxProduct, product);
        }
    }

    std::cout << "The greatest product of four adjacent numbers in the grid is: " << maxProduct << std::endl;

    return 0;
}


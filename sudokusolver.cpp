#include <iostream>
#include <iomanip>

#define UNASSIGNED 0
#define N 9

bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if 'num' is not in the given row
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Check if 'num' is not in the given column
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    // Check if 'num' is not in the 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool findUnassignedLocation(int grid[N][N], int& row, int& col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool solveSudoku(int grid[N][N]) {
    int row, col;

    // If there is no unassigned location, we are done
    if (!findUnassignedLocation(grid, row, col))
        return true;

    // Consider digits 1 to 9
    for (int num = 1; num <= 9; num++) {
        // If looks promising
        if (isSafe(grid, row, col, num)) {
            // Make tentative assignment
            grid[row][col] = num;

            // Return, if success
            if (solveSudoku(grid))
                return true;

            // Failure, unmake & try again
            grid[row][col] = UNASSIGNED;
        }
    }
    return false; // This triggers backtracking
}

void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            std::cout << grid[row][col] << " ";
        std::cout << std::endl;
    }
}

int main() {
    int grid[N][N] = {
        {5, 3, UNASSIGNED, UNASSIGNED, 7, UNASSIGNED, UNASSIGNED, UNASSIGNED, UNASSIGNED},
        {6, UNASSIGNED, UNASSIGNED, 1, 9, 5, UNASSIGNED, UNASSIGNED, UNASSIGNED},
        {UNASSIGNED, 9, 8, UNASSIGNED, UNASSIGNED, UNASSIGNED, UNASSIGNED, 6, UNASSIGNED},
        {8, UNASSIGNED, UNASSIGNED, UNASSIGNED, 6, UNASSIGNED, UNASSIGNED, UNASSIGNED, 3},
        {4, UNASSIGNED, UNASSIGNED, 8, UNASSIGNED, 3, UNASSIGNED, UNASSIGNED, 1},
        {7, UNASSIGNED, UNASSIGNED, UNASSIGNED, 2, UNASSIGNED, UNASSIGNED, UNASSIGNED, 6},
        {UNASSIGNED, 6, UNASSIGNED, UNASSIGNED, UNASSIGNED, UNASSIGNED, 2, 8, UNASSIGNED},
        {UNASSIGNED, UNASSIGNED, UNASSIGNED, 4, 1, 9, UNASSIGNED, UNASSIGNED, 5},
        {UNASSIGNED, UNASSIGNED, UNASSIGNED, UNASSIGNED, 8, UNASSIGNED, UNASSIGNED, 7, 9}
    };

    if (solveSudoku(grid))
        printGrid(grid);
    else
        std::cout << "No solution exists";

    return 0;
}

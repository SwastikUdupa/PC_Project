#include <bits/stdc++.h>

#define UNASSIGNED 0
#define N 9


bool unassignedLoc(int grid[N][N], int &row, int &col)
{
for (row = 0; row < N; row++)
    for (col = 0; col < N; col++)
        if (grid[row][col] == UNASSIGNED)
            return true;
return false;
}

bool inRow(int grid[N][N], int row, int num)
{
for (int col = 0; col < N; col++)
    if (grid[row][col] == num)
        return true;
return false;
}

bool inCol(int grid[N][N], int col, int num)
{
for (int row = 0; row < N; row++)
    if (grid[row][col] == num)
        return true;
return false;
}

bool inBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
for (int row = 0; row < 3; row++)
    for (int col = 0; col < 3; col++)
        if (grid[row+boxStartRow][col+boxStartCol] == num)
            return true;
return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    return !inRow(grid, row, num) &&
           !inCol(grid, col, num) &&
           !inBox(grid, row - row%3 , col - col%3, num);
}


void printGrid(int grid[N][N])
{
for (int row = 0; row < N; row++)
{
   for (int col = 0; col < N; col++)
         printf("%d ", grid[row][col]);
    printf("\n");
}
}

bool SolveSudoku(int grid[N][N])
{
int row, col;
if (!unassignedLoc(grid, row, col))
   return true; 

for (int num = 1; num <= 9; num++)
{
    if (isSafe(grid, row, col, num))
    {
    	//backtracking logic lies here
        grid[row][col] = num;

        if (SolveSudoku(grid))
            return true;

        grid[row][col] = UNASSIGNED;
    }
}
return false;
}

int main()
{
int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                  {5, 2, 0, 0, 0, 0, 0, 0, 0},
                  {0, 8, 7, 0, 0, 0, 0, 3, 1},
                  {0, 0, 3, 0, 1, 0, 0, 8, 0},
                  {9, 0, 0, 8, 6, 3, 0, 0, 5},
                  {0, 5, 0, 0, 9, 0, 6, 0, 0},
                  {1, 3, 0, 0, 0, 0, 2, 5, 0},
                  {0, 0, 0, 0, 0, 0, 0, 7, 4},
                  {0, 0, 5, 2, 0, 6, 3, 0, 0}};
if (SolveSudoku(grid) == true)
      printGrid(grid);
else
     printf("No solution exists");

return 0;
}
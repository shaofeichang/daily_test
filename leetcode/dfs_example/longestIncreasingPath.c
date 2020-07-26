/*
    329. 矩阵中的最长递增路径
    给定一个整数矩阵，找出最长递增路径的长度。
    对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
    示例 1:
    输入: nums = 
    [
      [9,9,4],
      [6,6,8],
      [2,1,1]
    ] 
    输出: 4 
    解释: 最长递增路径为 [1, 2, 6, 9]。
*/
#include "../c_include.h"
const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int rows, columns;

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return 0;
    }
    rows = matrixSize;
    columns = matrixColSize[0];

    int** memo = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        memo[i] = (int*)malloc(sizeof(int) * columns);
        memset(memo[i], 0, sizeof(int) * columns);
    }
    int ans = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            ans = fmax(ans, dfs(matrix, i, j, memo));
        }
    }
    free(memo);
    return ans;
}

int dfs(int** matrix, int row, int column, int** memo) {
    if (memo[row][column] != 0) {
        return memo[row][column];
    }
    ++memo[row][column];
    for (int i = 0; i < 4; ++i) {
        int newRow = row + dirs[i][0], newColumn = column + dirs[i][1];
        if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[row][column]) {
            memo[row][column] = fmax(memo[row][column], dfs(matrix, newRow, newColumn, memo) + 1);
        }
    }
    return memo[row][column];
}

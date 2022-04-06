// @Title: Number of Enclaves
// @Author: colinjxc
// @Date: 2022-02-12T18:22:57+08:00
// @URL: https://leetcode-cn.com/problems/number-of-enclaves


void dfs(int** grid, int gridSize, int ColSize, int i, int j, int *res) {
  if (i < 0 || i == gridSize || j < 0 || j == ColSize || grid[i][j] == 0) {
    return;
  }
  *res = *res -1;
  grid[i][j] = 0;
  dfs(grid, gridSize, ColSize, i, j - 1, res);
  dfs(grid, gridSize, ColSize, i - 1, j, res);
  dfs(grid, gridSize, ColSize, i, j + 1, res);
  dfs(grid, gridSize, ColSize, i + 1, j, res);
}

int numEnclaves(int** grid, int gridSize, int* gridColSize){
  int cnt1 = 0;
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridColSize[0]; j++) {
      cnt1 += grid[i][j];
    }
  }

  for (int i = 0; i < gridColSize[0]; i++) {
    dfs(grid, gridSize, gridColSize[0], 0, i, &cnt1);
    dfs(grid, gridSize, gridColSize[0], gridSize - 1, i, &cnt1);
  }

  for (int i = 0; i < gridSize; i++) {
    dfs(grid, gridSize, gridColSize[0], i, 0, &cnt1);
    dfs(grid, gridSize, gridColSize[0], i, gridColSize[0] - 1, &cnt1);
  }

  return cnt1;
}

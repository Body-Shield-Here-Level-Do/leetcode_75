#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void dfs(vector<vector<char>> &grid, int row, int col) {
    // 邊緣的情境
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
      return;
    }

    if (grid[row][col] == '2' || grid[row][col] == '0') {
      return;
    }

    grid[row][col] = '2';

    // 判斷上下左右的部份是否為已經為：
    // 判斷過的狀態(2)或是海(0)
    dfs(grid, row + 1, col);
    dfs(grid, row, col - 1);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
  }

  int numIslands(vector<vector<char>> &grid) {
    int islands = 0;
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[0].size(); col++) {
        if (grid[row][col] == '1') {
          dfs(grid, row, col);
          ++islands;
        }
      }
    }
    return islands;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<char>> grid1 = {
      {'1', '1', '1', '1', '0'},
      {'1', '1', '0', '1', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '0', '0', '0'},
  };
  vector<vector<char>> grid2 = {
      {'1', '1', '0', '0', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '1', '0', '0'},
      {'0', '0', '0', '1', '1'},
  };
  Solution sol;
  assert(sol.numIslands(grid1) == 1);
  assert(sol.numIslands(grid2) == 3);
  cout << "Success!" << endl;
  return 0;
}

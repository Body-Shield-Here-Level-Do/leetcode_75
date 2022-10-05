#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> res;

  bool is_valid(const vector<string> &board, int row, int col) {
    // 基本上同一列只會放入一個 Q -> ["..Q.", "Q..." ...]
    // 所以不用檢查同一列，也是主要嘗試的是否正確的方式之一。

    // 檢查同一欄
    for (int i = row; i >= 0; i--) {
      if (board[i][col] == 'Q') {
        return false;
      }
    }
    // 往左下右上檢查
    for (int i = row, j = col; j < board.size() && i >= 0; i--, j++) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }
    // 往左上右下檢查
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }

  // 固定其他參數的比較，以 `row`為唯一變因
  void dfs(vector<string> &board, int row) {
    if (row == board.size()) {
      res.push_back(board);
      return;
    }
    for (int i = 0; i < board.size(); i++) {
      if (is_valid(board, row, i)) {
        board[row][i] = 'Q';
        dfs(board, row + 1);
        board[row][i] = '.';
      }
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    if (n <= 0) {
      return {{}};
    }
    vector<string> board(n, string(n, '.'));
    dfs(board, 0);
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  for (auto &v : sol.solveNQueens(5)) {
    for (string &s : v) {
      for (char &c : s) {
        cout << c << ' ';
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}

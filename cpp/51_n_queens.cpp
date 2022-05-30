#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> res;

  // 因放入順序會是由左至右由上往下，所以檢查的方向則相反
  bool is_valid(const vector<string> &board, int row, int col) {
    // 檢查當前列之前欄中是否有 Queen 在攻擊範圍中
    for (int i = row; i >= 0; i--) {
      if (board[i][col] == 'Q') {
        return false;
      }
    }
    // 往右上檢查
    for (int i = row, j = col; j < board.size() && i >= 0; i--, j++) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }
    // 往左上檢查
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }

  void dfs(vector<string> &board, int row) {
    if (row == board.size()) {
      res.push_back(board);
      return;
    }

    for (int i = 0; i < board.size(); i++) {
      // 驗證通過後會加入 `board` 中，而經過後續皆驗證成功後。
      // 會將當前符合條件的 `board` 紀錄至 `res` 中。
      // 並返回原始狀態，進行後續檢查。
      if (is_valid(board, row, i)) {
        board[row][i] = 'Q';
        dfs(board, row + 1);
        board[row][i] = '.';
      }
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    // 若當前為 0，則回傳空。
    if (n <= 0) {
      return {{}};
    }
    vector<string> board(
        n, string(n, '.')); // 建立一個 n x n 的二維 `char` 矩陣，作為棋盤。
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

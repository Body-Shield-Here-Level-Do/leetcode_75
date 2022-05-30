#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display(const vector<string> &matrix) {
  for (auto row : matrix) {
    for (char c : row) {
      cout << c << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

class NQueens {
public:
  vector<vector<string>> ans;

  bool is_valid(const vector<string> &board, int row, int col) {
    for (int i = row; i >= 0; i--) {
      if (board[i][col] == 'Q') {
        return false;
      }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }
    for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }

  void attack_range(const vector<string> &board, int row, int col) {
    vector<string> choice = board;
    // 90 degree
    for (int i = 0; i < row; i++) {
      choice[i][col] = (choice[i][col] == 'Q') ? 'q' : 'x';
    }
    // 135 degree
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
      choice[i][j] = (choice[i][j] == 'Q' && i != row && j != col) ? 'q' : 'x';
    }
    // 45 degree
    for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
      choice[i][j] = (choice[i][j] == 'Q' && i != row && j != col) ? 'q' : 'x';
    }
    display(choice);
  }

  void dfs(vector<string> &board, int row, int n) {
    if (row == n) {
      ans.push_back(board);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (is_valid(board, row, i)) {
        board[row][i] = 'Q';
        attack_range(board, row, i);
        cout << "row = " << row << endl;
        cout << "col = " << i << endl;
        dfs(board, row + 1, n);
        board[row][i] = '.';
      }
    }
  }

  vector<vector<string>> run(int n) {
    vector<string> board(n, string(n, '.'));
    dfs(board, 0, n);
    return ans;
  }
};

int main(int argc, char *argv[]) {
  NQueens nq;
  nq.run(4);
  return 0;
}

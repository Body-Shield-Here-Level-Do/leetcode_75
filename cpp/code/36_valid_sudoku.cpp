#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValidSudoku(const vector<vector<char>> &board) {
    int row[9][9] = {0}; // 檢查 9 列中，9 個數字的重複次數
    int col[9][9] = {0}; // 檢查 9 行中，9 個數字的重複次數
    int block[3][3][9] = {0}; // 檢查 9 個 3x3 的矩陣中，9 個數字的重複次數

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {

          int num = board[i][j] - '0'; // 轉換 char 成為 int
          int idx = num - 1; // 轉換數字為對應計數陣列的索引

          // 列檢查
          if (row[i][idx]++) {
            return false;
          }
          // 行檢查
          if (col[j][idx]++) {
            return false;
          }
          // 3x3 方格檢查
          if (block[i / 3][j / 3][idx]++) {
            return false;
          }
        }
      }
    }
    return true;
  }
};

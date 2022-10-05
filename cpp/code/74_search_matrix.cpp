#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++) {
      if (matrix[i][m] >= target) {
        int left = 0, right = m - 1;
        while (left <= right) {
          int mid = (left + right) / 2;
          if (target == matrix[i][mid]) {
            return true;
          } else if (target > matrix[i][mid]) {
            right = mid - 1;
          } else {
            left = mid + 1;
          }
        }
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  Solution sol;
  cout << (sol.searchMatrix(matrix, 3) ? "Pass!" : "Fail!") << endl;
  return 0;
}

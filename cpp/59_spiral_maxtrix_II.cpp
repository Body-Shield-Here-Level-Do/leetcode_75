#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int left = 0, right = n - 1;
    int top = 0, bottom = n - 1;
    int cur = 1;

    while (cur <= n * n) {
      for (int i = left; i <= right; i++) {
        ans[top][i] = cur++;
      }
      top++;

      for (int i = top; i <= bottom; i++) {
        ans[i][right] = cur++;
      }
      right--;

      for (int i = right; i >= left; i--) {
        ans[bottom][i] = cur++;
      }
      bottom--;

      for (int i = bottom; i >= top; i--) {
        ans[i][left] = cur++;
      }
      left++;
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  cout << '[' << endl;
  for (auto v : sol.generateMatrix(3)) {
    cout << '[' << ' ';
    for (int i : v) {
      cout << i << ' ';
    }
    cout << ']' << endl;
  }
  cout << ']' << endl;

  return 0;
}

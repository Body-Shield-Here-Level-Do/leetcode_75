#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<vector<string>> dp(n + 1);
    dp[0] = {""};
    // 列索引：紀錄 n 長度對應的結果
    for (int i = 1; i <= n; i++) {
      // 左括弧索引
      for (int j = 0; j < i; j++) {
        for (auto &x : dp[i - j - 1]) {
          for (auto &y : dp[j]) {
            dp[i].push_back("(" + y + ")" + x);
          }
        }
      }
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  for (string s : sol.generateParenthesis(3)) {
    cout << s << endl;
  }
  return 0;
}

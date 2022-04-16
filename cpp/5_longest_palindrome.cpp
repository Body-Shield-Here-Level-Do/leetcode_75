#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int N = s.length();
    bool dp[N][N]; // 動態規劃
    memset(dp, 0, sizeof(dp));
    int start = 0, len = 0;

    for (int k = 0; k < N; k++) {               // 控制字串長度
      for (int i = 0, j = k; j < N; i++, j++) { // 控制開始與結束的位置
        // 當字串長度為 0 則對稱
        if (k == 0) {
          dp[i][j] = 1;
        }
        // 當字串長度為 1 也是對稱
        else if (k == 1) {
          if (s[i] == s[j]) {
            dp[i][j] = 1;
          }
        }
        // 其餘則需要判斷
        else {
          // 若比對頭尾字元相同，且其中間字元相同則為對稱
          if (s[i] == s[j] && dp[i + 1][j - 1]) {
            dp[i][j] = 1;
          }
        }
        // 若當前判斷為對稱則持續推導下去，而最終結果最長的字串會在第一列
        if (dp[i][j]) {
          start = i;
          len = j - i + 1;
        }
      }
    }
    return s.substr(start, len);
  }
};

int main(int argc, char *argv[]) {
  string s{"babad"};
  Solution sol;
  cout << sol.longestPalindrome(s) << endl;
  return 0;
}

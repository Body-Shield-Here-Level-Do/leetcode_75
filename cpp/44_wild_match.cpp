#include <iostream>
#include <string>
#include <vector>

using namespace std;

string fmt_array(const vector<int> &v) {
  string fmt("[ ");
  for (int i : v) {
    fmt += to_string(i) + ' ';
  }
  fmt.push_back(']');
  return fmt;
}

string fmt_2D_array(const vector<vector<int>> &v) {
  string fmt("[ ");
  for (auto iv : v) {
    fmt += "\n " + fmt_array(iv);
  }
  fmt += "\n]";
  return fmt;
}

class Solution {
public:
  bool isMatch(string s, string p) {
    vector<vector<int>> dp(p.length() + 1, vector<int>(s.length() + 1));
    dp[0][0] = 1;
    cout << "Initialize:" << endl;
    cout << fmt_2D_array(dp) << endl;
    for (int i = 1; i <= p.length(); i++) {
      dp[i][0] = p[i - 1] == '*' && dp[i - 1][0];
    }
    cout << "Find * in pattern:" << endl;
    cout << fmt_2D_array(dp) << endl;
    for (int i = 1; i <= p.length(); i++) {
      for (int j = 1; j <= s.length(); j++) {
        if (p[i - 1] == '*') {
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
          cout << "Get " << p[i - 1] << ':' << endl;
          cout << fmt_2D_array(dp) << endl;
        } else if (p[i - 1] == '?' || p[i - 1] == s[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
          cout << "Get " << p[i - 1] << ':' << endl;
          cout << fmt_2D_array(dp) << endl;
        }
      }
    }
    return dp.back().back();
  }
};

int main(int argc, char *argv[]) {
  string s("aa");
  string p("*a");
  Solution sol;

  cout << (sol.isMatch(s, p) ? "PASS" : "FAIL") << endl;
  return 0;
}

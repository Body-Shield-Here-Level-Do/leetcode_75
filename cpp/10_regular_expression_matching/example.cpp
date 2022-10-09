#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class BottomUp
{
  void print_matrix(const std::vector<std::vector<int>>& m)
  {
    for (auto& v : m)
    {
      for (int i : v)
      {
        std::cout << i << ' ';
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

 public:
  bool isMatch(std::string, std::string);
};

bool BottomUp::isMatch(std::string s, std::string p)
{
  std::vector<std::vector<int>> dp(s.length() + 1,
                                   std::vector<int>(p.length() + 1, 0));
  dp[s.length()][p.length()] = 1;

  for (int i = s.length(); i >= 0; i--)
  {
    for (int j = p.length() - 1; j >= 0; j--)
    {
      bool curr_match = p[j] == s[i] || p[j] == '.' && i < s.length();

      if (j + 1 < p.length() && p[j + 1] == '*')
      {
        dp[i][j] = (curr_match && dp[i + 1][j]) || dp[i][j + 2];
      }
      else
      {
        dp[i][j] = curr_match && dp[i + 1][j + 1];
      }
      std::cout << "curr_match = " << (curr_match ? "True" : "False")
                << std::endl;
      std::cout << "i = " << i << '\t' << "j = " << j << std::endl;
      print_matrix(dp);
    }
  }
  return dp[0][0];
}

class TopDown
{
  std::string ss, pp;

 public:
  bool dfs(int i, int j);
  bool isMatch(std::string s, std::string p);
};

bool TopDown::dfs(int i, int j)
{
  // 兩字串配對成功?
  if (j == pp.length())
  {
    return i == ss.length();
  }

  // 當前字元配對成功?
  bool curr_match = i < ss.length() && pp[j] == '.' || pp[j] == ss[i];

  if (j + 1 < pp.length() && pp[j + 1] == '*')
  {
    return dfs(i, j + 2) ||              // `*`配對零次
           curr_match && dfs(i + 1, j);  // `*`配對一次
  }
  return curr_match && dfs(i + 1, j + 1);  // 現在、下次配對成功?
}
bool TopDown::isMatch(std::string s, std::string p)
{
  ss = s, pp = p;
  return dfs(0, 0);
}

int main(int argc, char* argv[])
{
  // BottomUp sol = BottomUp();
  TopDown sol = TopDown();

  assert(!sol.isMatch("aa", "a"));
  assert(sol.isMatch("aa", "a*"));
  assert(sol.isMatch("ab", ".*"));
  assert(sol.isMatch("abcd", "ab.*d"));

  std::cout << "All Pass!" << std::endl;

  return 0;
}

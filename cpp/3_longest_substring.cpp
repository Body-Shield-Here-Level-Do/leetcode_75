#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int idx = 0, max = 0;
    string longest;
    while (idx != s.length()) {
      if (longest.find(s[idx]) != string::npos) {
        longest = longest.substr(longest.find(s[idx]) + 1);
      }
      longest.push_back(s[idx]);
      max = max > longest.length() ? max : longest.length();
      idx++;
    }
    return max;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  printf("%d\n", sol.lengthOfLongestSubstring("abcabcbb"));
  return 0;
}

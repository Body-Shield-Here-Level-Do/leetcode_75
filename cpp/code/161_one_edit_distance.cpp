#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool oneEditDistance(const string &s, const string &t) {
    int i = 0, j = 0;
    int time = 0;
    while (i < s.length() && j < t.length()) {
      cout << "s: " << s[i] << endl;
      cout << "t: " << t[j] << endl;
      if (s[i] != t[j]) {
        time++;
        if (s.length() > t.length()) {
          j++;
          continue;
        } else if (s.length() < t.length()) {
          i++;
          continue;
        }
      }
      i++, j++;
    }
    return time <= 1;
  }
};

int main(int argc, char *argv[]) {
  string s = "cab", t = "ad";
  Solution sol;
  cout << (sol.oneEditDistance(s, t) ? "Pass" : "Fail") << endl;
  return 0;
}

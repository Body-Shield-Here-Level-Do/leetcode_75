#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define printvar(var) getname(var, #var)

template <typename T> void getname(T var, const char *name) {
  cout << name << ":\t" << var << endl;
}

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    // 若長度不同則為 false
    if (s.length() != t.length()) {
      return false;
    }

    string su{s[0]}, tu{t[0]}; // 建立一個不重複的字串紀錄
    vector<int> sp(s.length(), 0),
        tp(t.length(), 0); // 建立一個紀錄字元回寫的索引
    int idx = 0;

    while (idx < s.length()) {
      if (su.find(s[idx]) == string::npos) {
        su.push_back(s[idx]);
      }
      if (tu.find(t[idx]) == string::npos) {
        tu.push_back(t[idx]);
      }
      sp[idx] = su.find(s[idx]);
      tp[idx] = tu.find(t[idx]);
      idx++;
    }
    return sp == tp;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  cout << (sol.isIsomorphic("foo", "bar") ? "True" : "False") << endl;
  return 0;
}

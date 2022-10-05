#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> strs) {
    if (strs.size() == 1) {
      return {{strs[0]}};
    }
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mp;
    for (auto &str : strs) {
      string tmp = str;
      sort(tmp.begin(), tmp.end());
      mp[tmp].push_back(str);
    }
    for (auto &i : mp) {
      ans.push_back(i.second);
    }
    return ans;
  }
};

int main(int argc, char *argv[]) { return 0; }

#include "src/display.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(const vector<int> &nums) {
    int max_len = nums.empty() ? 0 : 1;
    vector<int> dp(nums.size(), 1);
    cout << print_vec(dp) << endl;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          cout << nums[i] << "(nums[" << i << "]) > " << nums[j] << "(nums["
               << j << "])" << endl;
          dp[i] = max(dp[i], dp[j] + 1);
          max_len = max(max_len, dp[i]);
        }
        cout << print_vec(dp) << endl;
      }
    }
    return max_len;
  }
};

int main(int argc, char *argv[]) {
  vector<int> testcase({0, 1, 4, 1, 2});
  Solution sol;
  cout << sol.lengthOfLIS(testcase) << endl;
  return 0;
}

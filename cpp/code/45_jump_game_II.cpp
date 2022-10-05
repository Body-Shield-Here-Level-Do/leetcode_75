#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // Recursive -> Dynamic Programming
  // long long int jump(vector<int> nums, int curr, int dest) {
  //   if (curr >= dest) {
  //     return 0;
  //   }
  //
  //   long long int tmp = INT_MAX;
  //
  //   for (int i = 1; i <= nums[curr]; i++) {
  //     tmp = min(tmp, 1 + jump(nums, curr + i, dest));
  //   }
  //
  //   return tmp;
  // }
  //
  // int jump(const vector<int> &nums) { return jump(nums, 0, nums.size() - 1);
  // }

  int jump(const vector<int> &nums) {
    int n = nums.size(), idx = 0, max_reachable = 0, last_position = 0,
        jump_steps = 0;

    while (last_position < n - 1) {
      max_reachable = max(max_reachable + 1, idx + nums[idx]);

      if (idx == last_position) {
        last_position = max_reachable;
        jump_steps++;
      }
      idx++;
    }
    return jump_steps;
  }
};

int main(int argc, char *argv[]) {
  vector<int> case1 = {2, 3, 1, 1, 4};
  Solution sol;
  cout << sol.jump(case1) << endl;
  return 0;
}

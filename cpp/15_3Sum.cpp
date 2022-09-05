#include "src/display.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    if (nums.size() < 3) {
      return {};
    }
    if (nums[0] > 0) {
      return {};
    }

    vector<vector<int>> res;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        break;
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int left = i + 1, right = nums.size() - 1;
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum > 0) {
          right--;
        } else if (sum < 0) {
          left++;
        } else {
          res.push_back({nums[i], nums[left], nums[right]});
          int last_low_occurence = nums[left],
              last_high_occurence = nums[right];
          while (left < right && nums[left] == last_low_occurence) {
            left++;
          }
          while (left < right && nums[right] == last_high_occurence) {
            right--;
          }
        }
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  vector<int> nums{-1, 0, 1, 2, -1, -4};
  sol.threeSum(nums);
  return 0;
}

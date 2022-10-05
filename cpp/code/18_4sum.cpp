#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    set<vector<int>> store;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int new_target = target - nums[i] - nums[j];
        int x = j + 1, y = n - 1;

        while (x < y) {
          int sum = nums[x] + nums[y];

          if (sum > new_target) {
            y--;
          } else if (sum < new_target) {
            x++;
          } else {
            store.insert({nums[i], nums[j], nums[x], nums[y]});
            x++;
            y--;
          }
        }
      }
    }

    copy(store.begin(), store.end(), ans);

    return ans;
  }
};

int main(int argc, char *argv[]) { return 0; }

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(const vector<int> &nums) {
    int max = nums[0];
    int sum = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      sum += nums[i];

      // 若是當前數字比較前面總和大，表示現在此數字是最大總和的 subarray
      if (nums[i] > sum) {
        sum = nums[i];
      }

      if (sum > max) {
        max = sum;
      }
    }
    return max;
  }
};

int main(int argc, char *argv[]) {}

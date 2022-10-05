#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == val) {
        cnt++;
      } else {
        nums[i - cnt] = nums[i];
      }
    }
    return nums.size() - cnt;
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums = {2, 3, 3, 2};
  Solution sol;
  cout << sol.removeElement(nums, 3) << endl;
  return 0;
}

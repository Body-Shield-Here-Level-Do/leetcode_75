#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> result;

  string fmt(const vector<int> &nums) {
    string res;
    res.push_back('[');
    res.push_back(' ');
    for (int i : nums) {
      char c = i + '0';
      res.push_back(c);
      res.push_back(' ');
    }
    res.push_back(']');
    return res;
  }

  void permutation(vector<int> &nums, int i, int n) {
    // 若索引與陣列長度相同，則將當前加入 `result` 中。
    // 為遞迴函式的終點
    if (i == n) {
      result.push_back(nums);
      cout << "result: " << result.size() << endl << endl;
      return;
    }
    // 將兩兩索引上的記憶體位置對調
    for (int j = i; j <= n; j++) {

      // cout << "first: swap(" << i << ", " << j << ")" << endl;
      swap(nums[i], nums[j]);
      // cout << "nums: " << fmt(nums) << endl << endl;

      // cout << "permutation(" << fmt(nums) << ", " << i + 1 << ", " << n <<
      // ")"
      //      << endl
      //      << endl;
      permutation(nums, i + 1, n);

      // cout << "second: swap(" << i << ", " << j << ")" << endl;
      swap(nums[i], nums[j]);
      // cout << "nums: " << fmt(nums) << endl << endl;
    }
  }

  vector<vector<int>> permute(vector<int> &nums) {
    // cout << "permutation(" << fmt(nums) << ", " << 0 << ", " << nums.size() -
    // 1
    //      << ")" << endl
    //      << endl;
    permutation(nums, 0, nums.size() - 1);
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums = {1, 2, 3};
  Solution sol;
  sol.permute(nums);
  for (auto &v : sol.result) {
    for (int i : v) {
      cout << i << ' ';
    }
    cout << endl;
  }
  return 0;
}

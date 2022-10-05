#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(const vector<int> &nums, int target) {

    vector<int> result(2, -1);
    int n = nums.size();

    // binary search 三劍客
    int l = 0, r = n - 1; // 左邊界與右邊界

    while (l <= r) {
      int mid = (l + r) / 2; // 中間點

      // 若搜尋到中間點的數值為目標值，表示
      // 左側可能有值，且可能是最小索引的目標值
      // 右側可能有值，且可能是最大索引的目標值
      if (target == nums[mid]) {
        // 先向左確認最小索引
        int check_left = mid;
        while (check_left >= 0) {
          if (nums[check_left] != target) {
            break;
          }
          check_left--;
        }
        result[0] = check_left + 1;

        // 向右確認最大索引
        int check_right = mid;
        while (check_right < nums.size()) {
          if (nums[check_right] != target) {
            break;
          }
          check_right++;
        }
        result[1] = check_right - 1;

        return result;
      }
      // 針對已經排列過的array
      // 若目標值大於中間點，則目標值可能在中點右側
      else if (nums[mid] < target) {
        l = mid + 1; // 推移左側邊界
      } else {
        r = mid - 1; // 相反地推移右側邊界
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v{1};
  Solution sol;
  for (auto &i : sol.searchRange(v, 1)) {
    cout << i << endl;
  }
  return 0;
}

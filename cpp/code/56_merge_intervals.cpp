#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end()); // 確保範圍順序是由小到大

    vector<vector<int>> ans;
    int n = intervals.size();
    int res = 0; // 紀錄結果數量

    for (int i = 1; i < n; i++) { // 比較 `res` 與 `i` 索引下的物件
      // 若發生範圍重疊的情況
      if (intervals[i][0] <= intervals[res][1]) {
        // 以 [1, 3], [2, 6] 為例，其中具備重疊的條件。
        // 所以需要整合，而整合後的陣列會變成 [1, 6]。
        intervals[res][0] = min(intervals[res][0], intervals[i][0]);
        intervals[res][1] = max(intervals[res][1], intervals[i][1]);
      }
      // 其餘則不影響原始 `intervals` 繼續遍歷
      else {
        res++;
        intervals[res] = intervals[i]; // 將確認後的結果推至前方
      }
    }

    // 將結果紀錄於 `ans` 中
    for (int i = 0; i <= res; i++) {
      ans.push_back(intervals[i]);
    }

    return ans;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> v1{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> v2{{1, 4}, {4, 5}};

  Solution sol;
  for (auto v : sol.merge(v2)) {
    for (int i : v) {
      cout << i << ' ';
    }
    cout << endl;
  }
  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int idx1 = m - 1, idx2 = n - 1, j = m + n - 1; // j 為最終整合後的陣列長度
    // 將 nums2 整合至 nums1，使用 nums2 的索引為基準
    while (idx2 >= 0) {
      if (idx1 >= 0 && nums1[idx1] > nums2[idx2]) {
        nums1[j--] = nums1[idx1--];
      } else {
        nums1[j--] = nums2[idx2--];
      }
    }
  }
};

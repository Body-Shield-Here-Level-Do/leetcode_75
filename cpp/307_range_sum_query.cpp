#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FenWickTree {
  vector<int> nums;

public:
  FenWickTree(vector<int> &v) : nums(vector<int>(v.size() + 1, 0)) {
    for (int i = 0; i < v.size(); i++) {
      update(i, v[i]);
    }
  }

  void update(int index, int val) {
    while (index < nums.size()) {
      nums[index] += val;
      index += lowbit(index);
    }
  }

  int query(int a) {
    int sum = 0;
    while (a > 0) {
      sum += nums[a];
      a -= lowbit(a);
    }
    return sum;
  }

  int lowbit(int x) { return (x) & (-x); }
};

class SegmentTree {
  int L, R, val;
  SegmentTree *left{}, *right{};

  void build(vector<int> &nums) {
    if (L == R) {
      val = nums[L];
    } else {
      int mid = (L + R) / 2;
      left = new SegmentTree(nums, L, mid);
      right = new SegmentTree(nums, mid + 1, R);
      val = left->val + right->val;
    }
  }

public:
  SegmentTree(vector<int> &nums, int l, int r) : L(l), R(r) { build(nums); }

  void update(int index, int new_val) {
    if (L == R) {
      val = new_val;
    } else {
      int mid = (L + R) / 2;
      if (index <= mid) {
        left->update(index, new_val);
      } else {
        right->update(index, new_val);
      }
      val = left->val + right->val;
    }
  }

  int sumRange(int low, int high) {
    if (low > high) {
      return 0;
    }
    if (low == L && high == R) {
      return val;
    }
    int mid = (L + R) / 2;
    return left->sumRange(low, min(mid, high)) +
           right->sumRange(max(low, mid + 1), high);
  }
};

class NumArray {
  SegmentTree *tree;
  FenWickTree fw;

public:
  NumArray(vector<int> &nums)
      : tree(new SegmentTree(nums, 0, nums.size() - 1)), fw(nums) {}

  void update(int index, int val) {
    tree->update(index, val);
    // fw.update(index, val);
  }

  int sumRange(int left, int right) {
    return tree->sumRange(left, right);
    // return fw.query(right + 1) - fw.query(left);
  }
};

int main(int argc, char *argv[]) { return 0; }

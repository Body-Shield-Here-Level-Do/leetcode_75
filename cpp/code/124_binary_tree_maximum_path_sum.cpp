#include "src/Tree.h"
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxSum = INT_MIN;

  int dfs(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    int lmax = max(dfs(node->left), 0);
    int rmax = max(dfs(node->right), 0);
    int total = node->val + lmax + rmax;
    maxSum = max(maxSum, total);
    return node->val + max(lmax, rmax);
  }

  int maxPathSum(TreeNode *root) {
    dfs(root);
    return maxSum;
  }
};

int main(int argc, char *argv[]) {
  auto *test1 = new TreeNode(1, new TreeNode(2, nullptr, nullptr),
                             new TreeNode(3, nullptr, nullptr));
  Solution sol;
  cout << sol.maxPathSum(test1) << endl;
  return 0;
}

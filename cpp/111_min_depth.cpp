#include "src/Tree.hpp"

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
  int depth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int ld = depth(root->left);
    int rd = depth(root->right);

    if (ld == 0 || rd == 0) {
      return 1 + max(ld, rd);
    }
    return 1 + min(ld, rd);
  }

  int minDepth(TreeNode *root) { return depth(root); }
};

int main(int argc, char *argv[]) {
  Solution sol;
  TreeNode *case1 = new TreeNode(
      2, nullptr,
      new TreeNode(
          3, nullptr,
          new TreeNode(4, nullptr, new TreeNode(5, nullptr, new TreeNode(6)))));
  TreeNode *case2 = new TreeNode(
      3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

  TreeNode *case3 = nullptr;
  TreeNode *case4 = new TreeNode(
      1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));

  cout << sol.minDepth(case4) << endl;

  return 0;
}

#include "src/Tree.hpp"
#include <ios>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    // 邊界判斷
    if (p == nullptr || q == nullptr) {
      return p == q;
    }
    // 鬼才沒什麼好說的
    if ((p->val == q->val) && isSameTree(p->left, q->left) &&
        isSameTree(p->right, q->right)) {
      return true;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode *q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  Solution sol;
  return sol.isSameTree(p, q);
}

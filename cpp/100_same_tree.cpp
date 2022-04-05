#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  // Constructor.
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}

  void bfs() {}
};

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

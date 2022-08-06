#include "src/Tree.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  void flatten(TreeNode *root) {
    // morris traversal
    TreeNode *cur = root;
    while (cur != nullptr) {
      if (cur->left != nullptr) {
        TreeNode *runner = cur->left;
        while (runner->right != nullptr) {
          runner = runner->right;
        }
        runner->right = cur->right;
        cur->right = cur->left;
        cur->left = nullptr;
      }
      cur = cur->right;
    }
  }
};

int main(int argc, char *argv[]) { return 0; }

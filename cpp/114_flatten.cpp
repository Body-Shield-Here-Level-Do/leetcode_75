#include "src/Tree.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  void flatten(TreeNode *root) {
    if (root) {
      TreeNode *temp = root->right;
      root->right = root->left;
      root->left = nullptr;
      TreeNode *node = root;
      while (node->right) {
        node = node->right;
      }

      node->right = temp;
      flatten(root->right);
    }
    return;
  }
};

int main(int argc, char *argv[]) { return 0; }

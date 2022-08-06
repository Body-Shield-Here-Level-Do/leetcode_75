#include <string>
#include <vector>

#ifndef TREE_H_
#define TREE_H_

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  std::vector<int> fmt;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x, ...) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}

  std::vector<int> inorder(TreeNode *root) {
    if (root == nullptr) {
      return fmt;
    }
    inorder(root->left);
    fmt.push_back(root->val);
    inorder(root->right);
    return fmt;
  }

  std::vector<int> preorder(TreeNode *root) {
    if (root == nullptr) {
      return fmt;
    }
    fmt.push_back(root->val);
    inorder(root->left);
    inorder(root->right);
    return fmt;
  }

  std::vector<int> postorder(TreeNode *root) {
    if (root == nullptr) {
      return fmt;
    }
    inorder(root->left);
    inorder(root->right);
    fmt.push_back(root->val);
    return fmt;
  }

  std::vector<int> morris(TreeNode *root) {
    TreeNode *cur = root;
    while (cur != nullptr) {
      if (cur->left != nullptr) {
        TreeNode *temp = cur->left;
        while (temp->right != nullptr) {
          temp = temp->right;
        }
        temp->right = cur->right;
        cur->right = cur->left;
        cur->left = nullptr;
      }
      fmt.push_back(cur->val);
      cur = cur->right;
    }
    return fmt;
  }
};

#endif // !TREE_H_

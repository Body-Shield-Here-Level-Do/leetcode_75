#include <string>
#include <vector>

#ifndef TREE_HPP
#define TREE_HPP

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x, ...) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}

  std::vector<std::string> dfs();
  std::vector<std::string> wfs();
  std::vector<std::string> inorder();
};

#endif // !TREE_HPP

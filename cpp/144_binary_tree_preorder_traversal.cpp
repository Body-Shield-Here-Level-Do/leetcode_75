#include "src/Tree.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> result;

  vector<int> preorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return result;
    }
    result.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    return result;
  }
};

void display(Solution sol, TreeNode *root) {
  cout << '[' << ' ';
  for (int i : sol.preorderTraversal(root)) {
    cout << i << ' ';
  }
  cout << ']' << endl;
}

int main(int argc, char *argv[]) {
  auto *test1 =
      new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
  Solution sol;
  display(sol, test1);

  return 0;
}

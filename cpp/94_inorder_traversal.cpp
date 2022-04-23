#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x, ...) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
private:
  void print_vector(const vector<int> &v) {
    cout << '[';
    for (int i : v) {
      cout << i << ' ';
    }
    cout << ']' << endl;
  }

public:
  // Recursive
  void inorder(int step, vector<int> &v, TreeNode *cur) {
    if (cur == nullptr) {
      return;
    }
    inorder(step, v, cur->left);

    v.push_back(cur->val);
    cout << "step " << ++step << " - ";
    print_vector(v);

    inorder(step, v, cur->right);
  }

  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> v;
    int counter = 0;
    inorder(counter, v, root);
    return v;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root =
      new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
  Solution sol;
  sol.inorderTraversal(root);
  return 0;
}

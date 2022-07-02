#include "src/Tree.h"
#include <cstdint>
#include <queue>

using namespace std;

class Solution {
public:
  TreeNode *firstMistake, *secondMistake, *pre;

  void inorder(TreeNode *node) {
    if (node == nullptr) {
      return;
    }

    inorder(node->left);

    if (firstMistake == nullptr && node->val < pre->val) {
      firstMistake = pre;
    }
    if (firstMistake != nullptr && node->val < pre->val) {
      secondMistake = node;
    }
    pre = node;

    inorder(node->right);
  }

  void recoverTree(TreeNode *root) {
    pre = new TreeNode(INT32_MIN);
    inorder(root);
    swap(firstMistake->val, secondMistake->val);
  }
};

/*
 *     5
 *    / \
 *   6   8
 *      /
 *     4
 *
 * inorder(5)
 * +-------------------------+
 * |firstMistake = nullptr;  |
 * |secondMistake = nullptr; |
 * |pre = INT32_MIN;         |
 * +-------------------------+
 * |
 * |
 * |- inorder(6)
 * |  +-------------------------+
 * |  |firstMistake = nullptr;  |
 * |  |secondMistake = nullptr; |
 * |  |pre = 6;                 |
 * |  +-------------------------+
 * |
 * inorder(5)
 * +-------------------------+
 * |firstMistake = 6;        |
 * |secondMistake = nullptr; |
 * |pre = 5;                 |
 * +-------------------------+
 * |
 * |
 * |- inorder(8)
 *    +-------------------------+
 *    |firstMistake = 6;        |
 *    |secondMistake = nullptr; |
 *    |pre = 5;                 |
 *    +-------------------------+
 *    |
 *    |
 *    |- inorder(4)
 *    |  +-------------------------+
 *    |  |firstMistake = 6;        |
 *    |  |secondMistake = 4;       |
 *    |  |pre = 4;                 |
 *    |  +-------------------------+
 *    |
 *    |
 *    inorder(8)
 *    +-------------------------+
 *    |firstMistake = 6;        |
 *    |secondMistake = 4;       |
 *    |pre = 8;                 |
 *    +-------------------------+
 *
 * swap(6, 4);
 *
 *     5
 *    / \
 *   4   8
 *      /
 *     6
 */

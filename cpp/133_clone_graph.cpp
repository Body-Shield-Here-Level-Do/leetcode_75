#include "src/Graph.h"
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  Node *dfs(Node *cur, unordered_map<Node *, Node *> &mp) {
    vector<Node *> neighbour;
    Node *clone = new Node(cur->val);
    mp[cur] = clone;

    for (auto it : cur->neighbors) {
      if (mp.find(it) != mp.end()) {
        neighbour.push_back(mp[it]);
      } else {
        neighbour.push_back(dfs(it, mp));
      }
    }
    clone->neighbors = neighbour;
    return clone;
  }

  Node *cloneGraph(Node *node) {
    if (node == nullptr) {
      return nullptr;
    }
    if (node->neighbors.empty()) {
      return new Node(node->val);
    }
    unordered_map<Node *, Node *> mp;
    return dfs(node, mp);
  }
};

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool iscycle(vector<int> adj[], vector<int> &vis, int id) {
    if (vis[id] == 1) {
      return true;
    }
    if (vis[id] == 0) {
      vis[id] = 1;
      for (auto edge : adj[id]) {
        if (iscycle(adj, vis, edge)) {
          return true;
        }
      }
    }
    vis[id] = 2;
    return false;
  }

  bool canFinish(int numCourses, const vector<vector<int>> &prerequisites) {
    vector<int> adj[numCourses];
    for (auto edge : prerequisites) {
      adj[edge[1]].push_back(edge[0]);
    }
    vector<int> vis(numCourses, 0);

    for (int id = 0; id < numCourses; id++) {
      if (iscycle(adj, vis, id)) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  bool result = sol.canFinish(4, {{1, 3}, {2, 1}, {3, 0}});
  bool result2 = sol.canFinish(2, {{1, 0}, {0, 1}});
  if (result2) {
    cout << "Finished!" << endl;
  } else {
    cout << "Not Finished!" << endl;
  }
  return 0;
}

/*

numCourses = 4;
prerequisites = {{1, 3}, {2, 1}, {3, 0}};

for (auto edge : prerequisites) { adj[edge[1]].push_back(edge[0]); }
+---------------------------+
|adj = {{3}, {2}, {}, {1}}; |
|vis = {0, 0, 0, 0};        |
+---------------------------+

id = 0;
iscycle(adj, vis, 0)
| +---------------------------+
| |adj = {{3}, {2}, {}, {1}}; |
| |vis = {1, 0, 0, 0};        |
| +---------------------------+
|
|--iscycle(adj, vis, 3)
 | +---------------------------+
 | |adj = {{3}, {2}, {}, {1}}; |
 | |vis = {1, 0, 0, 1};        |
 | +---------------------------+
 |
 |--iscycle(adj, vis, 1)
  | +---------------------------+
  | |adj = {{3}, {2}, {}, {1}}; |
  | |vis = {1, 1, 0, 1};        |
  | +---------------------------+
  |
  |--iscycle(adj, vis, 2)
   | +---------------------------+
   | |adj = {{3}, {2}, {}, {1}}; |
   | |vis = {1, 1, 2, 1};        |
   | +---------------------------+
   |
   v
   false (line: 33)

id = 1;
iscycle(adj, vis, 1)
| +---------------------------+
| |adj = {{3}, {2}, {}, {1}}; |
| |vis = {0, 1, 0, 0};        |
| +---------------------------+
|
|--iscycle(adj, vis, 2)
 | +---------------------------+
 | |adj = {{3}, {2}, {}, {1}}; |
 | |vis = {0, 1, 2, 0};        |
 | +---------------------------+
 |
 v
 false (line: 33)

id = 2;
iscycle(adj, vis, 2)
| +---------------------------+
| |adj = {{3}, {2}, {}, {1}}; |
| |vis = {0, 0, 2, 0};        |
| +---------------------------+
|
v
false (line: 33)

id = 3;
iscycle(adj, vis, 3)
| +---------------------------+
| |adj = {{3}, {2}, {}, {1}}; |
| |vis = {1, 0, 0, 1};        |
| +---------------------------+
|
|--iscycle(adj, vis, 1)
 | +---------------------------+
 | |adj = {{3}, {2}, {}, {1}}; |
 | |vis = {1, 1, 0, 1};        |
 | +---------------------------+
 |--iscycle(adj, vis, 2)
 |  +---------------------------+
 |  |adj = {{3}, {2}, {}, {1}}; |
 |  |vis = {1, 1, 2, 1};        |
 |  +---------------------------+
 |
 v
 false (line: 33)

true (line: 37)

*/

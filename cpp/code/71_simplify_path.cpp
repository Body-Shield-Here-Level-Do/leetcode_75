#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    stack<string> st;
    string res;

    for (int i = 0; i < path.size(); i++) {
      // 限制條件在 /home//foo/ 情境下可以避免重複分隔符出現
      if (path[i] == '/') {
        continue;
      }
      string temp;
      // 限制條件在 /home 與 /home/ 情境下可以找出正確路徑字串
      while (i < path.size() && path[i] != '/') {
        temp += path[i++];
      }

      // 限制條件在 /home/. 情境下能夠避免出現
      if (temp == ".") {
        continue;
      }
      // 限制條件在 /home/.. 情境下能夠找出正確路徑字串
      else if (temp == "..") {
        if (!st.empty()) {
          st.pop();
        }
      } else {
        st.push(temp);
      }
    }

    // 整理每個有效地路徑字串
    while (!st.empty()) {
      res = "/" + st.top() + res;
      st.pop();
    }

    // 限制條件在 "" 情境下會回傳根目錄 "/"
    if (res.size() == 0) {
      return "/";
    }

    return res;
  }
};

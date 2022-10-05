#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st; // 使用 stack

    // 若是長度小於2 -> 不成對
    if (s.length() <= 1) {
      return false;
    }

    // 若是第一位為右側括弧 -> 不成對
    if (s[0] == '}' || s[0] == ']' || s[0] == ')') {
      return false;
    }

    for (int i = 0; i < s.length(); i++) {
      // 當遭遇右側括弧時
      if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
        // 表示目前沒有找到對應左括弧 -> 不成對
        if (st.empty()) {
          return false;
        }
        char match = st.top(); // 將最後放入的左括弧指定給 match
        st.pop();              // 清理已經比對物件

        // 與左括弧最接近的右側括弧若非相同種類括弧 -> 不成對
        if ((match == '[' && s[i] != ']') || (match == '{' && s[i] != '}') ||
            (match == '(' && s[i] != ')')) {
          return false;
        }
      }
      st.push(s[i]); // 若為左側括弧則推入堆疊
    }
    return st.empty(); // 若皆有成功比對的情況堆疊應為空
  }
};

int main(int argc, char *argv[]) { return 0; }

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    stack<string> st;

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {
        continue;
      }
      string temp;
      while (i < s.length() && s[i] != ' ') {
        temp.push_back(s[i++]);
      }
      st.push(temp);
    }

    if (st.empty()) {
      return "";
    }

    string result = st.top();
    st.pop();
    while (!st.empty()) {
      result += (' ' + st.top());
      st.pop();
    }
    return result;
  }
};

int main(int argc, char *argv[]) { return 0; }

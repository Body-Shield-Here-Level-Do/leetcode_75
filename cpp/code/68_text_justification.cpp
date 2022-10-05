#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string spaceJustifier(string s, int maxWidth, int isLast) {
    if (s.length() == maxWidth) {
      return s;
    }

    int spaceInString = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {
        spaceInString++;
      }
    }

    int spaceToBeInserted = maxWidth - s.length();

    if (spaceInString == 0 || isLast == 1) {
      s.insert(s.length(), spaceToBeInserted, ' ');
      return s;
    }

    int eachSlot = spaceToBeInserted / spaceInString;
    int leftOverSpace = spaceToBeInserted % spaceInString;

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ' && (eachSlot > 0 || leftOverSpace > 0)) {
        int noOfSpaces = eachSlot + ((leftOverSpace--) > 0 ? 1 : 0);
        s.insert(i, noOfSpaces, ' ');
        i += noOfSpaces;
      }
    }
    return s;
  }

  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> result;
    string output = words[0];

    for (int i = 1; i < words.size(); i++) {
      if (output.length() + words[i].length() + 1 <= maxWidth) {
        output += " " + words[i];
      } else {
        output = spaceJustifier(output, maxWidth, 0);
        result.push_back(output);
        output = words[i];
      }
    }
    output = spaceJustifier(output, maxWidth, 1);
    result.push_back(output);
    return result;
  }
};

int main(int argc, char *argv[]) { return 0; }

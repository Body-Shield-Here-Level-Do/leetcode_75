#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:
  vector<int> plusOne(vector<int> &digits) {
    int carry = 0;
    for (int i = digits.size() - 1; i >= 0; i--) {
      // c1
      if (digits[i] == 9) {
        digits[i] = 0;
        carry = 1;
      }
      // c2
      else {
        // c2.1
        if (carry == 1) {
          carry = 0;
          digits[i] += 1;
          break;
        }
        // c2.2
        else {
          digits[i] += 1;
          break;
        }
      }
    }
    // c3
    if (carry == 1) {
      digits[0] = 1;
      digits.push_back(0);
    }
    return digits;
  }
};

int main(int argc, char *argv[]) { return 0; }

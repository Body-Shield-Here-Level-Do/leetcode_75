#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int factorial(int n) {
    if (n <= 1) {
      return 1;
    }
    int res = n;
    while (n > 1) {
      res *= (n - 1);
      n--;
    }
    return res;
  }

  string range_str(int n) {
    string res;
    for (int i = 0; i < n; i++) {
      res.push_back(char(i + 1 + '0'));
    }
    return res;
  }

  string getPermutation(int n, int k) {
    string res = range_str(n);
    for (int i = 0; i < n; i++) {
      sort(res.begin() + i, res.end());
      int choices = factorial(n - 1 - i);
      if (n - 1 - i > 0) {
        int swap_to = k / choices + i;
        if (k % choices == 0) {
          swap_to -= 1;
          k = choices;
        } else {
          k %= choices;
        }
        swap(res[i], res[swap_to]);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  assert(sol.getPermutation(3, 3) == "213");
  assert(sol.getPermutation(3, 1) == "123");
  assert(sol.getPermutation(4, 9) == "2314");
  assert(sol.getPermutation(2, 2) == "21");
  assert(sol.getPermutation(3, 2) == "132");
  cout << "Success!" << endl;
  cout << sol.getPermutation(9, 50) << endl;
  return 0;
}

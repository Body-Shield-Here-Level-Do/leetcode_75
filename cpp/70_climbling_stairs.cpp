#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    // 實際窮舉結果
    // n = 1, choice = 1
    // n = 2, choice = 2
    // n = 3, choice = 3 (1 + 2)
    // n = 4, choice = 5 (2 + 3)
    // n = 5, choice = 8 (3 + 5)

    // 依據實際推導，n <= 2時，選擇數量與階梯總數相同
    if (n <= 2) {
      return n;
    }
    int twoback = 1; // (n - 2 個階梯的種類數)
    int oneback = 2; // (n - 1 個階梯的種類數)
    int curr = 0;

    for (int i = 3; i <= n; i++) {
      curr = oneback + twoback; // n 個階梯的種類數 = (n - 1 個階梯的種類數) +
                                // (n - 2 個階梯的種類數)
      twoback = oneback;
      oneback = curr;
    }
    return curr;
  }
};

int main(int argc, char *argv[]) { return 0; }

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    vector<bool> v(n + 1, true);
    v[0] = false, v[1] = false; // 0 與 1 不為質數，所以質數判斷由 2 開始
    // 迴圈針對質數進行遍歷
    for (int i = 2; i * i <= n; i++) {
      if (v[i]) {
        // 這個條件很機車像是質數判斷公式解
        for (int j = i * i; j <= n; j += i) {
          v[j] = false;
        }
      }
    }
    // 最後統計質數的數量
    int counter = 0;
    for (int i = 2; i < n; i++) {
      if (v[i]) {
        counter++;
      }
    }
    return counter;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  cout << sol.countPrimes(10) << endl;
  return 0;
}

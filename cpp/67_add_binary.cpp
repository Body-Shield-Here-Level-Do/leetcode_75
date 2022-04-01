#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    string res;
    int i = a.length(), j = b.length(), carry = 0;

    while (i >= 0 || j >= 0) {
      int sum = carry;
      // idx-- 用於分別兩個索引進行推移
      if (i >= 0) {
        sum += a[i--] - '0'; // char - '0' 的部份則是將文字轉換為數字
      }
      if (j >= 0) {
        sum += b[j--] - '0';
      }
      carry = sum > 1 ? 1 : 0;   // 代表
      res += to_string(sum % 2); // 解析出當前數字
    }
    if (carry) {
      res += to_string(carry);
      reverse(res.begin(), res.end());
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  string a{"1"}, b{"11"};
  cout << sol.addBinary(a, b) << endl;
  return 0;
}

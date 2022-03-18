#include <iostream>

using namespace std;

class Solution {

public:
  int mySqrt(int x) {
    long long int left = 0, right = x;

    while (left <= right) {
      long long int mid;
      mid = (left + right) / 2;

      if (mid * mid == x) {
        return mid;
      } else if (mid * mid > x) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return right;
  }
};

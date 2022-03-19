#include <iostream>
#define EXAMPLE_CPP
#include <boost/stacktrace.hpp>
#include <time.h>

using namespace std;

int recursion(int cur, int max) {
  if (cur > max) {
    return 0;
  }
  cout << "當前數字：\t" << cur << endl;
  cout << "當前堆疊：\n" << boost::stacktrace::stacktrace() << endl;
  return recursion(cur + 1, max);
}

int loop(int cur, int max) {
  while (cur <= max) {
    cout << "當前數字：\t" << cur << endl;
    cout << "當前堆疊：\n" << boost::stacktrace::stacktrace() << endl;
    cur++;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  clock_t begin, end;
  int cur = 1, max = 5;

  begin = clock();
  cout << '\n' << "Recursion:" << '\n' << endl;
  recursion(cur, max);
  end = clock();
  cout << "Recursion execute time: " << (end - begin) << " ms" << endl;

  begin = clock();
  cout << '\n' << "Loop:" << '\n' << endl;
  loop(cur, max);
  end = clock();
  cout << "Loop execute time: " << (end - begin) << " ms" << endl;

  return 0;
}

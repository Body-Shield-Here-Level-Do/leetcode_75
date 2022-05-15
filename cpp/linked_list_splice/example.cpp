#include <iostream>
#include <iterator>
#include <list>
#include <string>

using namespace std;
#define print(val) getname(val, #val)

// source url:https://www.cplusplus.com/reference/list/list/splice/

void getname(list<int> l, const char *name) {
  cout << name << ':' << ' ';
  if (l.empty()) {
    cout << "(empty)" << endl;
    return;
  }
  auto it = l.begin();
  cout << '[' << ' ';
  while (it != l.end()) {
    cout << *it++ << ' ';
  }
  cout << ']' << endl;
}

void getname(list<int>::iterator val, const char *name) {
  cout << name << ':' << ' ' << *val << endl;
}

void getname(const string &val, const char *name) {
  cout << endl << string(val.size() + 1, '=') << endl;
  cout << val;
  cout << endl << string(val.size() + 1, '=') << endl;
}
int main(int argc, char *argv[]) {
  list<int>::iterator it;
  list<int> mylist1 = {1, 2, 3, 4};
  list<int> mylist2 = {10, 20, 30};
  print(mylist1);
  print(mylist2);

  it = mylist1.begin();
  ++it;
  print(it);

  mylist1.splice(it, mylist2);
  print("經過 mylist1.splice(it, mylist2) 後");
  print(mylist1);
  print(mylist2);
  print(it);

  mylist2.splice(mylist2.begin(), mylist1, it);
  print("經過mylist2.splice(mylist2.begin(), mylist1, it)後");
  print(mylist1);
  print(mylist2);
  print(it);

  it = mylist1.begin();
  advance(it, 3);
  print("經過advance(it, 3)後");
  print(it);

  mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
  print("經過mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end())後");
  print(mylist1);
  print(mylist2);
  print(it);
}

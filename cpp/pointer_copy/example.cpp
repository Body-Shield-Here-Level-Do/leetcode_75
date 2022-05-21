#include <iostream>
#include <string>

using namespace std;
#define showvar(val) print(val, #val)

template <typename T> void print(T obj, const char *name) {
  cout << name << ":\t" << obj << endl;
}

template <typename T> void is_same_address(const T *a, const T *b) {
  cout << ((a == b) ? "相同位址" : "不同位址") << endl;
}

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x, ...) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  string display() {
    ListNode *cur = this;
    string msg;
    while (cur != nullptr) {
      msg += (to_string(cur->val) + "->");
      cur = cur->next;
    }
    msg.append("NULL");
    return msg;
  }

  void append(int val) {
    ListNode *cur = this, *node = new ListNode(val);
    while (cur->next != nullptr) {
      cur = cur->next;
    }
    cur->next = node;
  }

  void insert(int pos, int val) {
    if (!valiadpos(pos)) {
      cout << "錯誤：pos " << pos << " 須小於等於串列長度" << endl;
      exit(0);
    }
    ListNode *cur = this, *node = new ListNode(val);
    int idx = 0;
    while (cur != nullptr) {
      if (idx == pos) {
        node->next = cur;
        cur = node;
        cur = cur->next;
      } else {
        cur = cur->next;
      }
      idx++;
    }
  }

private:
  bool valiadpos(int pos) {
    ListNode *cur = this;
    int idx = 0;
    while (cur != nullptr) {
      idx++;
      cur = cur->next;
    }
    return (pos <= idx);
  }
};

int main(int argc, char *argv[]) {
  ListNode *list1 = new ListNode(10, new ListNode(20));
  ListNode *fast_ref = list1->next;

  cout << "fast:" << fast_ref->display() << endl;
  cout << "list1:" << list1->display() << endl;

  fast_ref->append(5);
  cout << "fast 加入 5" << endl;

  cout << "fast:" << fast_ref->display() << endl;
  cout << "list1:" << list1->display() << endl;

  return 0;
}

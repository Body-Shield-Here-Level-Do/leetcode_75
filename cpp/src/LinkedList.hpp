#include <string>
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x, ...) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *n) : val(x), next(n) {}

public:
  std::string display() {
    ListNode *cur = this;
    std::string msg;
    while (cur != nullptr) {
      msg += (std::to_string(cur->val) + "->");
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
};

#endif // !LINKEDLIST_HPP

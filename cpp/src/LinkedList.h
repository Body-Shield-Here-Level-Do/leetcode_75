#pragma once
#include <string>

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x, ...) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *n) : val(x), next(n) {}

  std::string display_value(std::string s, ListNode *cur) {
    if (cur == nullptr) {
      s += "NULL";
      return s;
    }
    s += std::to_string(cur->val);
    s += "->";
    return display_value(s, cur->next);
  }

public:
  std::string display() { return display_value("", this); }

  void append(int val) {
    ListNode *cur = this, *node = new ListNode(val);
    while (cur->next != nullptr) {
      cur = cur->next;
    }
    cur->next = node;
  }

  ListNode *insert(int index, int val) {
    int idx = 0;
    ListNode *cur = this, *node = new ListNode(val);
    while (cur != nullptr) {
      if (idx == index) {
        node->next = cur;
        return node;
      }
      cur = cur->next;
      idx++;
    }
    return cur;
  }
};

#endif // !LINKEDLIST_H_

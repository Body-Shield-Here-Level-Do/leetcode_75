#include <iostream>
#include <string>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
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
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    // 空串列篩選
    if (head == nullptr) {
      return head;
    }
    // 單一串列元素篩選
    if (head->next == nullptr) {
      return head;
    }
    ListNode *slow = head, *fast = head->next;
    while (fast != nullptr) {
      string msg(20, '-');
      // c1
      if (fast->val != slow->val) {
        slow->next = fast;
        slow = fast;
        fast = fast->next;
      }
      // c2
      else {
        fast = fast->next;
      }
    }
    slow->next = fast; // 處理尾端最後一筆
    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->append(1);
  head->append(2);
  head->append(3);
  head->append(3);

  Solution sol;
  sol.deleteDuplicates(head);

  return 0;
}

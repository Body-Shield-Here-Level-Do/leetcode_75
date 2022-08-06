#include "src/LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

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

#include "src/LinkedList.h"
#include <iostream>

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *fast = head, *slow = head;
    for (int i = 0; i < n; i++) {
      fast = fast->next;
    }
    if (fast == nullptr) {
      return head->next;
    }
    while (fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
  }
};

int main(int argc, char *argv[]) {
  auto test1 = new ListNode(
      1, new ListNode(
             2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
  Solution sol;
  ListNode *res = sol.removeNthFromEnd(test1, 2);
  std::cout << "["
            << " ";
  while (res != nullptr) {
    std::cout << res->val << " ";
    res = res->next;
  }
  std::cout << "]" << std::endl;
}

#include <iostream>
#include <type_traits>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  void display() {
    ListNode *cur = this;
    while (cur != nullptr) {
      cout << cur->val << "->";
      cur = cur->next;
    }
    cout << "NULL" << endl;
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
      cout << "fast: " << fast->val << endl;
      cout << "slow: " << slow->val << endl;
      // c1
      if (fast->val != slow->val) {
        cout << "condition1" << endl;
        slow->next = fast;
        slow = fast;
        fast = fast->next;
      }
      // c2
      else {
        cout << "condition2" << endl;
        fast = fast->next;
      }
    }
    slow->next = fast; // 處理尾端最後一筆
    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(
      1, new ListNode(
             1, new ListNode(2, new ListNode(3, new ListNode(3, nullptr)))));
  head->display();
  Solution sol;
  sol.deleteDuplicates(head)->display();
  return 0;
}

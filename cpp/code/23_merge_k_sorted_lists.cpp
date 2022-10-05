#include "src/LinkedList.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *res;
  ListNode *mergeLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }
    ListNode *head = l1->val <= l2->val ? l1 : l2;
    head->next = l1->val <= l2->val ? mergeLists(l1->next, l2)
                                    : mergeLists(l1, l2->next);
    return head;
  }

  ListNode *mergeKLists(vector<ListNode *> lists) {
    if (lists.empty() || lists[0] == nullptr) {
      return {};
    }
    res = lists[0];
    cout << "res: " << res->display() << endl;
    for (int i = 1; i < lists.size(); i++) {
      res = mergeLists(res, lists[i]);
      cout << "res: " << res->display() << endl;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<ListNode *> test1 = {
      new ListNode(1, new ListNode(4, new ListNode(5, nullptr))),
      new ListNode(1, new ListNode(3, new ListNode(4, nullptr))),
      new ListNode(2, new ListNode(6, nullptr)),
  };
  Solution sol;
  sol.mergeKLists(test1);
  return 0;
}

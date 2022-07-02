#include "src/LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA;
    ListNode *b = headB;
    while (a != b) {
      a = (a == nullptr) ? headB : a->next;
      b = (b == nullptr) ? headA : b->next;
    }
    return a;
  }
};

int main(int argc, char *argv[]) {
  ListNode *listA = new ListNode(4);
  listA->append(1);
  listA->append(8);
  listA->append(4);
  listA->append(5);

  cout << listA->display() << endl;

  ListNode *listB = new ListNode(5);
  listB->append(6);
  listB->append(1);
  listB->append(8);
  listB->append(4);
  listB->append(5);

  cout << listB->display() << endl;

  Solution sol;
  cout << sol.getIntersectionNode(listA, listB)->display() << endl;

  return 0;
}

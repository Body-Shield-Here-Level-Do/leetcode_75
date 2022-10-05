#include "src/LinkedList.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {

    // Exceptions.
    if (head == nullptr || head->next == nullptr) {
      return nullptr;
    }

    // Linked list is circule ?
    bool cycle = false;
    ListNode *fast = head, *slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        cycle = true;
        break;
      }
    }
    if (!cycle) {
      return nullptr;
    }

    // Reset head pointer.
    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};

int main(int argc, char *argv[]) { return 0; }

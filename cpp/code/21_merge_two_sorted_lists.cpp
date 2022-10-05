#include "src/LinkedList.h"

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {

    // 兩種情況會回傳：
    //
    // 1. 當遍歷串列時(尾指標為nullptr)
    // 2. 當空串列時
    if (list1 == nullptr) {
      return list2;
    }
    if (list2 == nullptr) {
      return list1;
    }

    // 符合條件時，list1會前往下一筆資料
    if (list1->val <= list2->val) {
      list1->next = mergeTwoLists(list1->next, list2); // 將當前節點接至 list1
      return list1;
    }
    // 不符合條件時，list2會前往下一筆資料
    list2->next = mergeTwoLists(list1, list2->next); // 將當前節點接至 list2
    return list2;
  }
};

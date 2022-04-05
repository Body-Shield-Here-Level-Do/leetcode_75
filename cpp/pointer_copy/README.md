# 指定符號 `=` 是如何操作指標記憶體

---

藉由打印出記憶體名稱與位址來觀察指定符 `=` 的行為：

```cpp
#include <iostream>
#include <string>

using namespace std;
#define showvar(val) print(val, #val)

template <typename T> void print(T obj, const char *name) {
  cout << name << ":\t" << obj << endl;
}
```

簡易的位址比較來明白當前兩變數是否操作相同記憶體位址：

```cpp
template <typename T> void is_same_address(const T *a, const T *b) {
  cout << ((a == b) ? "相同位址" : "不同位址") << endl;
}
```

## 實際操作案例 (以 `LinkedList`為例)

變數定義：

```cpp
ListNode *list1 = new ListNode(10, new ListNode(20)); // [10 -> 20 -> NULL]
ListNode *slow_ref = list1, *fast_ref = list1->next;
```

比較是否操作**相同記憶體**：

```cpp
showvar(slow_ref), showvar(list1);
is_same_address(slow_ref, list1);

showvar(fast_ref), showvar(list1->next);
is_same_address(fast_ref, list1->next);
```

```
slow_ref:       0x563d4245feb0
list1:  0x563d4245feb0
相同位址

fast_ref:       0x563d4245fed0
list1->next:    0x563d4245fed0
相同位址
```

比較(複製)**指定後的變數變更**是否會影響原始記憶體：

```cpp
cout << "fast:" << fast_ref->display() << endl;
cout << "list1:" << list1->display() << endl;

fast_ref->append(5);
cout << "fast 加入 5" << endl;

cout << "fast:" << fast_ref->display() << endl;
cout << "list1:" << list1->display() << endl;
```

```
fast:20->NULL
list1:10->20->NULL

fast 加入 5

fast:20->5->NULL
list1:10->20->5->NULL
```

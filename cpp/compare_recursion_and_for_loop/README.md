# 為什麼遞迴會慢於迴圈？

遞迴(recursion)會呼叫自身作為函式的運算過程，而函式在呼叫的過程會將函式本身的推入堆疊(call stack)，增加其記憶體負擔造成計算過程不比迴圈(loop)快速。

## 案例比較

- recursion 印出整數 1 到 5：

```cpp
int recursion(int cur, int max) {
  if (cur > max) {
    return 0;
  }
  cout << "當前數字：\t" << cur << endl;
  // 回傳 call stak 狀態
  cout << "當前堆疊：\n" << boost::stacktrace::stacktrace() << endl;
  return recursion(cur + 1, max);
}
```

輸出資訊：

```
Recursion:

當前數字：	1
當前堆疊：
 0# 0x0000559AF3E8952C in ./a.out
 1# 0x0000559AF3E8974F in ./a.out
 2# 0x00007F3DA55E9310 in /usr/lib/libc.so.6
 3# __libc_start_main in /usr/lib/libc.so.6
 4# 0x0000559AF3E89395 in ./a.out

當前數字：	2
當前堆疊：
 0# 0x0000559AF3E8952C in ./a.out
 1# 0x0000559AF3E8956C in ./a.out
 2# 0x0000559AF3E8974F in ./a.out
 3# 0x00007F3DA55E9310 in /usr/lib/libc.so.6
 4# __libc_start_main in /usr/lib/libc.so.6
 5# 0x0000559AF3E89395 in ./a.out

當前數字：	3
當前堆疊：
 0# 0x0000559AF3E8952C in ./a.out
 1# 0x0000559AF3E8956C in ./a.out
 2# 0x0000559AF3E8956C in ./a.out
 3# 0x0000559AF3E8974F in ./a.out
 4# 0x00007F3DA55E9310 in /usr/lib/libc.so.6
 5# __libc_start_main in /usr/lib/libc.so.6
 6# 0x0000559AF3E89395 in ./a.out

當前數字：	4
當前堆疊：
 0# 0x0000559AF3E8952C in ./a.out
 1# 0x0000559AF3E8956C in ./a.out
 2# 0x0000559AF3E8956C in ./a.out
 3# 0x0000559AF3E8956C in ./a.out
 4# 0x0000559AF3E8974F in ./a.out
 5# 0x00007F3DA55E9310 in /usr/lib/libc.so.6
 6# __libc_start_main in /usr/lib/libc.so.6
 7# 0x0000559AF3E89395 in ./a.out

當前數字：	5
當前堆疊：
 0# 0x0000559AF3E8952C in ./a.out
 1# 0x0000559AF3E8956C in ./a.out
 2# 0x0000559AF3E8956C in ./a.out
 3# 0x0000559AF3E8956C in ./a.out
 4# 0x0000559AF3E8956C in ./a.out
 5# 0x0000559AF3E8974F in ./a.out
 6# 0x00007F3DA55E9310 in /usr/lib/libc.so.6
 7# __libc_start_main in /usr/lib/libc.so.6
 8# 0x0000559AF3E89395 in ./a.out

Recursion execute time: 212 ms

```

- `while` loop 印出整數 1 到 5：

```cpp
int loop(int cur, int max) {
  while (cur <= max) {
    cout << "當前數字：\t" << cur << endl;
	// 回傳 call stak 狀態
    cout << "當前堆疊：\n" << boost::stacktrace::stacktrace() << endl;
    cur++;
  }
  return 0;
}
```

輸出資訊：

```
Loop:

當前數字：	1
當前堆疊：
 0# 0x0000559AF3E89659 in ./a.out
 1# 0x0000559AF3E8980E in ./a.out
 2# 0x00007F3DA55E9310 in /usr/lib/libc.so.6
 3# __libc_start_main in /usr/lib/libc.so.6
 4# 0x0000559AF3E89395 in ./a.out

當前數字：	2
當前堆疊：
 0# 0x0000559AF3E89659 in ./a.out
 1# 0x0000559AF3E8980E in ./a.out
 2# 0x00007F3DA55E9310 in /usr/lib/libc.so.6
 3# __libc_start_main in /usr/lib/libc.so.6
 4# 0x0000559AF3E89395 in ./a.out

當前數字：	3
當前堆疊：
 0# 0x0000559AF3E89659 in ./a.out
 1# 0x0000559AF3E8980E in ./a.out
 2# 0x00007F3DA55E9310 in /usr/lib/libc.so.6
 3# __libc_start_main in /usr/lib/libc.so.6
 4# 0x0000559AF3E89395 in ./a.out

當前數字：	4
當前堆疊：
 0# 0x0000559AF3E89659 in ./a.out
 1# 0x0000559AF3E8980E in ./a.out
 2# 0x00007F3DA55E9310 in /usr/lib/libc.so.6
 3# __libc_start_main in /usr/lib/libc.so.6
 4# 0x0000559AF3E89395 in ./a.out

當前數字：	5
當前堆疊：
 0# 0x0000559AF3E89659 in ./a.out
 1# 0x0000559AF3E8980E in ./a.out
 2# 0x00007F3DA55E9310 in /usr/lib/libc.so.6
 3# __libc_start_main in /usr/lib/libc.so.6
 4# 0x0000559AF3E89395 in ./a.out

Loop execute time: 135 ms

```

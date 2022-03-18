---

Source_URL:: [stackexchange](https://cs.stackexchange.com/questions/56867/why-are-loops-faster-than-recursion?utm_source=pocket_mylist)

---

# 為什麼遞迴會慢於迴圈？

- 迴圈的組譯語言

```assembly
mov loopcounter, i
dowork:/do work
dec loopcounter
jmp_if_not_zero dowork
```

- 遞迴的組譯語言

```assembly
start_subroutine:
pop parameter1
pop parameter2
dowork: //dowork
test something
jmp_if_true done
push parameter1
push parameter2
call start_subroutine
done:ret
```

單單就步驟數量來看，迴圈理應會快於遞迴。

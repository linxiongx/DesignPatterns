# DesignPatterns

<details>
<summary>代码</summary>
```cpp
int  x = 27; // x 的型别是 int
const int cx = x; // cx 的型别是 const int
const int& rx =x; // rx 的型别是 const int&
//调用
f(x); // T 的型别是 int, param 的型别是 int&
f(cx); // T 的型别是 const int, param 的型别是 const int&
f(rx); // T 的型别是 const int, param 的型别是 const int&
```
</details>

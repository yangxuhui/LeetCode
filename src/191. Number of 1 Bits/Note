#Note
[Solution2:](http://www.tuicool.com/articles/YBbY3m)  

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n) {
            ++cnt;
            n = n & (n - 1);
        }
        return cnt;
    }
};
```

[Solution3:](http://www.tuicool.com/articles/YBbY3m)

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n) {
            if (n & 1) ++cnt;
            n = n >> 1;
        }
        return cnt;
    }
};
```

What's confusing is that LeetCode deduced solution1, 2 to be execute 11ms, but solution3 9ms.

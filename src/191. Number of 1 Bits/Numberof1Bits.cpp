// Source: https://leetcode.com/problems/number-of-1-bits
// 2015/3/29

// My Solution
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            if (n % 2) ++cnt;
            n = n / 2;
        }
        return cnt;
    }
}; // 11ms

// Using C++ bitset class
class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bitvec(n);
        return bitvec.count();
    }
}; // 4ms


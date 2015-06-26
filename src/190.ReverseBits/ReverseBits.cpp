// Source: https://leetcode.com/problems/reverse-bits/
// 2015/6/26

// My Solution
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bitvec1(n);
        bitset<32> bitvec2;
        for (int i = 31, ix = 0; i >= 0; --i, ++ix)
            if (bitvec1.test(i)) bitvec2.set(ix);
        return bitvec2.to_ulong();
    }
}; // 4ms
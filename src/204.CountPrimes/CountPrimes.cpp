// Source: 
// 2015/7/2

// Reference https://leetcode.com/discuss/33694/my-easy-one-round-c-code
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        int ret = 1, upper = sqrt(n);
        for (int i = 3; i < n; i+=2) {
            if (isPrime[i]) {
                ret++;
                if (i > upper ) continue;
                for (int j = i * i; j < n; j+=i)
                    isPrime[j] = false;
            }
        }
        return ret;
    }
}; // 216ms
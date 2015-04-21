// Source: https://leetcode.com/problems/3sum-closest/
// 2015/4/14

// My Solution
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int ret = 0;
        if (num.size() == 3) {
            for (auto elem : num)
                ret += elem;
            return ret;
        }
        sort(num.begin(), num.end());
        // initialize ret with first three elements
        int fst = 0, sec = 1, trd = 2;
        ret = num[fst] + num[sec] + num[trd];
        while (fst != num.size() - 2) {
            // skip the duplications
            if (fst != 0)
                while (fst != num.size() - 3 && num[fst] == num[fst-1]) ++fst;
            sec = fst + 1;
            while (sec != num.size() - 1) {
                trd = num.size() - 1;
                while (sec < trd) {
                    int sum = num[fst] + num[sec] + num[trd];
                    if (sum == target) return target;
                    // because sum is the max value of these fst and sec,
                    // if sum < target, then these sum is the closest to the target
                    if (sum < target) {
                        if (abs(sum - target) < abs(ret - target))
                            ret = sum;
                        break;
                    } else {
                        if (abs(sum - target) < abs(ret - target))
                            ret = sum;
                        do {
                            --trd;
                        } while (sec < trd && num[trd] == num[trd+1]);
                    }
                }
                do {
                    ++sec;
                } while (sec != num.size() - 1 && num[sec] == num[sec-1]);
            }
            ++fst;
        }
        return ret;
    }
}; // 26ms

// Reference haoel
// (https://github.com/haoel/leetcode/blob/master/algorithms/3SumClosest/3SumClosest.cpp)
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int ret = 0;
        int sz = num.size();
        if (sz == 3) {
            for (auto elem : num)
                ret += elem;
            return ret;
        }
        sort(num.begin(), num.end());
        int dis = INT_MAX;
        for (int fst = 0; fst < sz - 2; ++fst) {
            if (fst > 0 && num[fst] == num[fst-1]) continue;
            int scd = fst + 1;
            int trd = sz - 1;
            while (scd < trd) {
                int sum = num[fst] + num[scd] + num[trd];
                if (sum == target) return target;
                else {
                    if (abs(sum - target) < dis) {
                        dis = abs(sum - target);
                        ret = sum;
                    }
                    if (sum < target) {
                        while (scd < sz && num[scd] == num[scd+1]) ++scd;
                        ++scd;
                    } else {
                        while (trd > 0 && num[trd] == num[trd-1]) --trd;
                        --trd;
                    }
                }
            }
        }
        return ret;
    }
}; // 24ms
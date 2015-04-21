// Source: https://leetcode.com/problems/3sum/
// 2015/4/13

// My Solution
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        if (num.size() < 3) return ret;
        sort(num.begin(), num.end());
        int fst = 0;
        while (fst != num.size() - 2) {
            int scd = fst + 1;
            while (scd != num.size() - 1) {
                int trd = num.size() - 1;
                while (trd != scd) {
                    if (num[fst] + num[scd] + num[trd] < 0) break;
                    if (num[fst] + num[scd] + num[trd] == 0) {
                        vector<int> tmp;
                        tmp.push_back(num[fst]);
                        tmp.push_back(num[scd]);
                        tmp.push_back(num[trd]);
                        ret.push_back(tmp);
                        break;
                    }
                    do {
                        --trd;
                    } while (trd != scd && num[trd] == num[trd+1]);
                }
                do {
                    ++scd;
                } while (scd != num.size()-1 && num[scd] == num[scd-1]);
            }
            do {
                ++fst;
            } while (fst != num.size()-2 && num[fst] == num[fst-1]);
        }
        return ret;
    }
}; // 90ms

// Reference haoel
// (https://github.com/haoel/leetcode/blob/master/algorithms/3Sum/3Sum.cpp)
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        int sz = num.size();
        if (sz < 3) return ret;
        sort(num.begin(), num.end());
        for (int fst = 0; fst < sz - 2; ++fst) {
            if (fst > 0 && num[fst] == num[fst-1]) continue;
            int scd = fst + 1;
            int trd = sz - 1;
            while (scd < trd) {
                int sum = num[fst] + num[scd] + num[trd];
                if (sum < 0) {
                    while (scd < sz && num[scd] == num[scd+1]) ++scd;
                    ++scd;
                } else if (sum == 0) {
                    vector<int> tmp;
                    tmp.push_back(num[fst]);
                    tmp.push_back(num[scd]);
                    tmp.push_back(num[trd]);
                    ret.push_back(tmp);
                    while (scd < sz && num[scd] == num[scd+1]) ++scd;
                    while (trd > 0 && num[trd] == num[trd-1]) --trd;
                    ++scd;
                    --trd;
                } else {
                    while (trd > 0 && num[trd] == num[trd-1]) --trd;
                    --trd;
                }
            }
        }
        return ret;
    }
}; // 71ms
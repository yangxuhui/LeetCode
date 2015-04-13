// Source: https://leetcode.com/problems/3sum/
// 2015/4/13

// My Solution
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        set<vector<int>> s;
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
                        s.insert(tmp);
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
        for (auto elem : s)
            ret.push_back(elem);
        return ret;
    }
}; // 124ms
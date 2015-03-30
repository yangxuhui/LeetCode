// Source: https://leetcode.com/problems/two-sum/
// 2015/3/30

//class Solution {
//public:
//    vector<int> twoSum(vector<int> &numbers, int target) {
//        vector<int> ret;
//        vector<int> tmp = numbers;
//        int a = 0, b = 0;
//        sort(tmp.begin(), tmp.end());
//        auto sz = numbers.size();
//        bool flag = false;
//        for (vector<int>::size_type ix = 0; ix != sz - 1; ++ix) {
//            auto ix2 = ix + 1;
//            while (ix2 != sz) {
//                if ((tmp[ix] + tmp[ix2]) >= target) {
//                    if ((tmp[ix] + tmp[ix2]) == target) {
//                        flag = true;
//                        a = tmp[ix];
//                        b = tmp[ix2];
//                    }
//                    break;
//                }
//                ++ix2;
//            }
//            if (flag) break;
//        }
//        int ix = 1;
//        for (auto elem : numbers) {
//            if (elem == a) ret.push_back(ix);
//            else if (elem == b) ret.push_back(ix);
//            if (ret.size() == 2) break;
//            ++ix;
//        }
//        sort(ret.begin(), ret.end());
//        return ret;
//    }
//}; // 38ms

//class Solution {
//public:
//    vector<int> twoSum(vector<int> &numbers, int target) {
//        // use a map to reduce the search from O(n) to O(1)
//        // the key is the number and the value is it's position
//        multimap<int, int> val_pos;
//        int pos = 0;// indicate the position
//        for (auto elem : numbers)
//            val_pos.insert({elem, pos++});
//        pos = 0;
//        vector<int> ret;// return value
//        for (auto elem : numbers) {
//            for (auto it = val_pos.equal_range(target - elem);
//                    it.first != it.second; ++it.first) {
//                if (it.first->second != pos) {
//                    ret.push_back(pos + 1);
//                    ret.push_back(it.first->second + 1);
//                    break;
//                }
//            }
//            if (ret.size()) break;
//            ++pos;
//        }
//        return ret;
//    }
//}; //36ms


// Thanks to haoel(https://github.com/haoel/leetcode/blob/master/src/twoSum/twoSum.cpp)
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        // key is the second number, value is the first number's position
        map<int, int> secVal_firPos;
        int pos = 0;
        for (auto elem : numbers) {
            // not found
            if (secVal_firPos.find(elem) == secVal_firPos.end())
                secVal_firPos[target - elem] = pos;
            else {// found
                ret.push_back(secVal_firPos[elem] + 1);
                ret.push_back(pos + 1);
                break;
            }
            ++pos;
        }
        return ret;
    }
}; // 27ms


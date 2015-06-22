// Source: https://leetcode.com/problems/compare-version-numbers/
// 2015/6/22

// My Solution
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1, vec2;
        versiontoVector(version1, vec1);
        versiontoVector(version2, vec2);
        int i = 0, j = 0;
        for (; i < vec1.size() && j < vec2.size(); ++i, ++j)
            if (vec1[i] < vec2[j]) return -1;
            else if (vec1[i] > vec2[j]) return 1;
        if (i == vec1.size() && j == vec2.size()) return 0;
        for (; i < vec1.size(); ++i)
            if (vec1[i] > 0) return 1;
        for (; j < vec2.size(); ++j)
            if (vec2[j] > 0) return -1;
        return 0;
    }
private:
    void versiontoVector(string version, vector<int> &v) {
        size_t pos = -1;
        do {
            size_t temp = pos + 1;
            pos = version.find('.', temp);
            v.push_back(stoi(version.substr(temp, pos - temp)));
        } while (pos != string::npos);
    }
}; // 0ms
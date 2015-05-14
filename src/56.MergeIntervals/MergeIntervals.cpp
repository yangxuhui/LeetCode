// Source: https://leetcode.com/problems/merge-intervals/
// 2015/5/14

// My Solution
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        int sz = intervals.size();
        if (sz == 0) return ret;
        if (sz == 1) return {intervals[0]};
        sort(intervals.begin(), intervals.end(),
             [](const Interval &a, const Interval &b)
               { return a.start < b.start;});
        for (int i = 1; i < sz; ++i) {
            int beg = intervals[i-1].start, ed = intervals[i-1].end;
            while (i < sz && intervals[i].start <= ed) {
                ed = intervals[i].end > ed ? intervals[i].end : ed;
                ++i;
            }
            ret.push_back(Interval(beg, ed));
        }
        if (ret[ret.size()-1].end < intervals[intervals.size()-1].end)
            ret.push_back(Interval(intervals[intervals.size()-1].start, intervals[intervals.size()-1].end));
        return ret;
    }
}; // 568ms
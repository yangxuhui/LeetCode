// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// 2015/6/6

// My Solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        vector<int> dailyChange(prices.size()-1);
        for (int i = 1; i < prices.size(); ++i)
            dailyChange[i-1] = prices[i] - prices[i-1];
        int profit = maximumSubarray(dailyChange);
        return profit > 0 ? profit : 0;
    }
private:
    int maximumSubarray(vector<int> &dailyChange) {
        int max = INT_MIN;
        for (int i = 0, contain_i = -1; i < dailyChange.size(); ++i) {
            contain_i = contain_i > 0 ? contain_i + dailyChange[i] : dailyChange[i];
            if (contain_i > max)
                max = contain_i;
        }
        return max;
    }
}; // 12ms

// Reference pezy
// https://github.com/pezy/LeetCode/blob/master/039.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock/solution.h
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int ret = 0, low = prices[0];
        for (auto price : prices) {
            low = std::min(low, price);
            ret = std::max(ret, price - low);
        }
        return ret;
    }
}; // 11ms
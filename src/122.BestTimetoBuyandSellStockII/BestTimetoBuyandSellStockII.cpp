// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// 2015/6/6

// My Solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i)
            if (prices[i] - prices[i-1] > 0)
                profit += (prices[i] - prices[i-1]);
        return profit;
    }
}; // 8ms
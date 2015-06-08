这道题我在《算法导论》中看过，所以先入为主，这也限制了我的思维。   
   
我的解法就用的《算法导论》中的方法，先算出相邻两天价格差值，然后将收益最大抽象成**价格差数组中最大子数组的和**，这样转化为计算价格差数组的最大子数组之和。前面已经做过最大子数组问题（[Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)）。   
   
这种做法需要很强的抽象能力，我只是看过解法，所以才能一下想到。
***
看了一下[pezy](https://github.com/pezy/LeetCode/blob/master/039.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock/solution.h)的解法，果然思路比上面的解法要简单不少。    
   
总体思路是**低买高卖**。具体来说，遍历数组，每次遇到当前最小的值后，其后面计算收益时减去当前最小值，与最大收益比较，更新当前最大收益。    
   
当然，[pezy](https://github.com/pezy/LeetCode/blob/master/039.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock/solution.h)的解法是经过优化的。

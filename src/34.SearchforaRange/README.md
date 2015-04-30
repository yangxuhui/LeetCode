这道题考察**二分查找(Binary Search)**，查找成功则前后比较确定范围(Range)，查找失败则返回{-1, -1}。  
  
需要注意的是，当有序序列所有元素都相同且为target时，查找一次成功，但确定范围却需要O(n)的时间复杂度，有趣的是，没有考虑这种情况也正常AC，且只用时15ms，算C++中较好的情况。  
  
如果考虑有序序列所有元素都相同且为target这种情况，可以在开始时增加逻辑判断：  
```cpp
if (nums[0] == nums[nums.size()-1] && nums[0] == target) return {0, nums.size()-1};
```  
***
有兴趣的可以学习一下[pezy](https://github.com/pezy/LeetCode/tree/master/067.%20Search%20for%20a%20Range) 对这道题的分析，他通过多次调用二分查找的办法将最坏情况考虑在内，整个时间复杂度O(logn)。是个值得注意的思路，但是个人感觉这道题目添加最坏情况的判断处理时最好的解决办法。

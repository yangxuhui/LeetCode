这道题从思路上来说并不难。我首先想到的是遍历数组，将每个正数记录到另一数组中，数值对应下标，即A[i] = i,这样遍历数组A，第一个A[i] != i时的i即为First Missing Positive。但是题目要求空间复杂度为O(1),这样不满足。  
   
如果记得[27 Remove Element](https://leetcode.com/problems/remove-element/) 和 [26 Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)的话，一定对于**原地构造数组**深有体会。  
   
这里的做法其实跟那两道题是相似的。我们遍历数组，遇到 0 < nums[i] <= nums.size() ，将其置于对应下标处。  
   
需要说明的是：  
   
* 由于可能出现数组只有一个元素且为1的情况，这时 1 肯定置于 nums[0]处，因此，我们所说的对应下标值的是以0为开始的情况。即，1 -> 0, 2 -> 1 ...
* 要求nums[i] <= nums.size() 是因为，这个数值不能（也没有必要）置于对应下标处，first missing positive 一定不会 > nums.size()。
   
***
核心代码：  
```cpp
for (int i = 0; i != nums.size(); ++i)
  while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i])
    swap(nums[i], nums[nums[i]-1]);  
```  
   
*** 
注意交换两个数用[swap](http://www.cplusplus.com/reference/algorithm/swap/)实现即可。

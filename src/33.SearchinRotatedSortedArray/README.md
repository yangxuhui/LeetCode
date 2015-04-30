开始时我的想法是先找到题目中所谓的 rotated pivot，这样我们就可以得到两个有序序列，分别对这两个有序序列进行**二分查找(Binary Search)**。  
  
这样做有一个问题，寻找 rotated pivot 的过程中，我们需要比较序列中相邻元素的大小，既然要从头开始寻找，为什么不在寻找的同时也查找 target ? 这样如果在寻找 rotated pivot 的过程中找到 target (target 存在且位于第一个有序序列)，就没有必要对第二个有序序列进行查找了(题目提示没有重复元素)；如果没有找到 target，只需要再对第二个有序序列进行二分查找。  
  
整个寻找 rotated pivot 的循环条件为 
```cpp
while (low < nums.size()-1 && nums[low] != target && nums[low] < nums[low+1]) ++low;
```
  
***
考虑最坏的情况，可能整个序列有序，没有 rotated pivot(题目的意思应该是存在 rotated pivot)，那么上面的解法时间复杂度为 O(n) ，因此，可以在最开始的时候判断整个序列是否有序，若有序则直接对整个序列进行二分查找。判断条件如下：  
```cpp
if (nums[low] < nums[nums.size()-1]) 
```

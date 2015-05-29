这里用[78 Subsets](https://github.com/yangxuhui/LeetCode/tree/master/src/78.Subsets)中的解法完全没问题。
***
这道题[pezy](https://github.com/pezy/LeetCode/tree/master/071.%20Subsets%20II)给出了一种更加简洁的[solution](https://github.com/pezy/LeetCode/tree/master/071.%20Subsets%20II)   
   
[pezy](https://github.com/pezy/LeetCode/tree/master/071.%20Subsets%20II)的解法是基于下面的子集求解过程：
   
以集合{1, 2, 3, 4}为例：  
    {}
    {}, {1}
    {}, {1}, {2}, {1,2}
    {}, {1}, {2}, {1,2}, {3}, {1,3}, {2,3}, {1,2,3}
    {}, {1}, {2}, {1,2}, {3}, {1,3}, {2,3}, {1,2,3}, {4}, {1,4}, {2,4}, {1,2,4}, {3,4}, {1,3,4}, {2,3,4}, {1,2,3,4}
       


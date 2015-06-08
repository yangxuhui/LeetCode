解决树的题，**首先要考虑递归**    
    
我立刻写出了下面的代码:
```cpp
if (!root) return 0;
else if (!root->left && !root->right) return root->val;
else return root->val + sumNumbers(root->left) + root->val + sumNumbers(root->right);
```
显然，上面的代码解决的是从根到叶子节点所有节点值之和，而题目要求将根到叶子节点所有节点值组成一个数字，计算所有路径之和。   
    
现在要解决的问题就是，如何将根到叶子所有节点值组成一个数字，我想到了将路径上所有节点值记录在一个字符串中，最后将所有字符串（即所有路径）转换为整数求和，显然这很麻烦。   
   
接下来想到的是每次累加每层节点值时，将上层值 * 10再加该层节点值即满足题目要求，这样需要引入额外的参数表示所有上层节点值组成的整数，所以定义了另外一个函数，引入该参数。   
   
核心代码为：
```cpp
int sumNumbers2(TreeNode* root, int sum) {
  if (!root) return 0;
  else if (!root->left && !root->right) return sum * 10 + root->val;
  else return sumNumbers2(root->left, sum * 10 + root->val) + sumNumbers2(root->right, sum * 10 + root->val); 
}

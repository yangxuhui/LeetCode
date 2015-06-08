我最会写层次遍历了，这道题最简答的思路莫过于层次遍历树，将每层节点链接起来。只是，层次遍历需要用到队列，随着层的增加，队列的长度也会增加，而题目要求空间复杂度O(1)。   
   
接下来我在纸上画了一棵树，每层从第一个节点开始，先将改节点的左右子节点链接，然后将该节点的右子节点与该节点的下一个节点的左子节点链接。   
   
核心代码如下：   
```cpp
if (!root) return;
while (root->left) {
  TreeNode *p = root;
  while (p->next) {
    p->right->next = p->next->left;
    p->next->left = p->next->right;
    p = p->next;
  }
  p->left->next = p->right;
  root = root->left;
}

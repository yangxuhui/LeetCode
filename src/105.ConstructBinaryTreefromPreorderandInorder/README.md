首先，这道题给了一个树中很重要的知识点：**先序序列（或者后序序列）与中序序列可以确定一棵二叉树**（当然，假设各个节点的值互不相同）    
    
作为二叉树的基础知识之一，就是要根据先序序列和中序序列构造这棵二叉树。我们回顾一下我们是如何操作的：   
```
           1   
         /   \
       2       3
     /        /
   4         5
              \
                6
    
先序序列：1   2   4   3   5   6   
          !
中序序列：4   2   1   5   6   3
                  !  
 ```   
 
根据先序序列，我们可以得到根节点，之后根据中序序列中根节点的位置，我们可以得到左子树包含的节点（根节点左边）以及右子树包含的节点（根节点右边），之后用同样的方法构造左右子树，这显然是递归的思想。    
   
需要注意的是，构造左右子树时我们需要左右子树各自的先序序列和中序序列，这个根据上面的图，确定一下起始位置就可以了。
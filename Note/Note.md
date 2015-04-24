# Something Learned From LeetCode
## 链表
### 删除链表节点   
#### 单链表   
   
对于一个单链表，现想要删除节点delNode,有两种方法（设delNode之前的节点为pre，之后的节点为nex）：   

**1. 方法一：**  
> * pre->next = nex;
> * pre->next = delNode->next;
> * pre->next = pre->next->next;  

可以看出，方法一有一个限制，即我们必须保存所删除节点的前一个节点。但是方法一浅显易懂。  

**2. 方法二：**
> * ListNode **del = &delNode; *del = (*del)->next;   

方法二利用了指针的指针，我们只需要保存所删除节点的信息即可完成删除操作，程序所需空间会减少。   
例题包括：  
[19 Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)



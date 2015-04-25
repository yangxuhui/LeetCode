# Something Learned From LeetCode
## 链表
### 单链表   
#### 删除链表节点   
   
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
#### 合并链表
##### 合并两个有序链表
严蔚敏版《数据结构》 P31 页的算法是我到目前为止看到的最为一目了然的写法：  
> ```
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc) {
   pa = La->next; pb = Lb->next;
   Lc = pc = La; // 用La的头结点作为Lc 的头结点
   while (pa && pb) {
      if (pa->data <= pb->data) {
         pc->next = pa; pc = pa; pa = pa->next;
      }
      else {
         pc->next = pb; pc = pb; pb = pb->next;
      }
   } 
   pc->next = pa ? pa : pb;
   free(Lb);
}
```   
  
这段代码有几个地方需要注意：  
1. 这段代码中三个链表均设有**头结点**（在单链表的第一个结点之前附设的一个辅助结点）。  
2. 这个算法破坏了La 和 Lb 两个链表，合并后的链表是在 La 和 Lb 的基础上构造的。  
3. 算法的时间复杂度为**O(La.length + Lb.length)**；空间复杂度为**O(1)**。  
***
[pezy](https://github.com/pezy/LeetCode/tree/master/019.%20Merge%20Two%20Sorted%20Lists) 提到可以利用递归完成:
> ```
if (La == NULL) return Lb;
if (Lb == NULL) return La;
if (La->data < Lb->data) {
   La->next = mergeTwoList(La->next, Lb);
   return La;
}
else {
   Lb->next = mergeTwoList(Lb->next, La);
   return Lb;
}
```  
  
例题包括[21 Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)




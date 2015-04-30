# Note of LeetCode
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
  
  
例题包括[21 Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)  

## 数组
### 删除数组元素
在数组中删除元素的含义是：**将这个元素放到数组的size之外**。例如数组[1, 1, 2]删除第二个元素后，数组为[1, 2, x], x 不确定，但是数组中元素的个数（size）为2，size 之外的东西不用考虑。  
   
例题包括 [27 Remove Element](https://leetcode.com/problems/remove-element/), [26 Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/).  
  
开始时我一直考虑删除一个元素后，后面的元素必须向前移动，其实在这几道题的背景下大可不必，每次删除元素都移动后面的元素只会导致超时，这两道题要求O(1) 的空间复杂度，所以要边删除元素，边构造数组，最后返回数组的长度即可，长度之外的东西与改数组无关。
  
## 字符串
### Search
#### find(找到一字符串在另一字符串中第一次出现的位置)
最简单的方法是利用**string** 的**find()** 方法。**string** 类提供了6种不同的search 函数（参考*《C++ Primer 5th》* 9.5.3 *string Search Operations*）。  
  
当然，我们应该尝试自己实现find操作，并与**string** 类的**find** 方法加以比较。  
***
以[28 Implement strStr()](https://leetcode.com/problems/implement-strstr/)为例：  
  

1. 如果追求快速与代码的简练，可以利用**string** 类的**find** 方法：
> ```
   int strStr(string haystack, string needle) {
      auto pos = haystack.find(needle);
      return (pos == string::npos) ? -1 : pos;
   } // 6ms 

  
2. 考虑自己实现find 操作  
> ``` 
   int strStr(string haystack, string needle) {
      if (needle.empty()) return 0;
      if (haystack.size() < needle.size()) return -1;
      int pos = -1;
      for (int i = 0; i < (haystack.size()-needle.size()+1);++i) {
         if (haystack[i] == needle[0]) {
            int j = 1, tmp_pos = i;
            for (int ix = i + 1; j != needle.size() && ix != haystack.size(); ++ix,++j)
               if (haystack[ix] != needle[j]) break;
            if (j == needle.size()) {
               pos = tmp_pos;
               break;
            }
         }
      }
      return pos;
   } // 8ms
 
这种实现思路很简单，从 haystack 的第一个字符开始与 needle 比较， 每次匹配失败之后，从下一个字符开始继续比较， 如果匹配到 needle ，则返回第一个字符的位置。注意：只需要迭代到**haystack.size() - needle.size()**,因为之后的字符串长度小于 needle 的长度，无需匹配(开始时我没有考虑到这一点，导致算法超时，增加这一条件后代码AC，而且可以看出，性能上并没有比第一种解法差太多)。  
  
   
- 有时间阅读**string** 类的**find**方法源码学习。可能用到了 [Rabin-Karp](http://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm), [KMP](http://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm) 或者是 [Boyer–Moore](http://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_string_search_algorithm) 算法 ？？？ 
  

***
细心的朋友可能注意到上面的解法二刚开始都有一个逻辑判断，如果 needle 为空的话返回0，这个条件在题目中并没有体现（抑或我没有看出来？），通过测试**string** 类的**find** 函数，发现确实**在参数为空字符串时 find 返回0。**    
  
## 查找
### 折半查找(Binary Search)
**折半查找**只适用于**有序表**的查找，且限于**顺序存储结构**。
> 算法代码如下：
```cpp
low = 0, high = length - 1; // 下标从0开始
while (low <= high) {
   mid = (low + high) / 2;
   if (ST[mid] == key) return mid;
   else if (ST[mid] < key) low = mid + 1;
   else high = mid - 1;
}
```  
  
折半查找有几个地方需要注意：  

1. 查找失败的条件是 high < low  
2. 算法的时间复杂度？？？  

***  
(完全没看懂LeetCode题目标号的标准，个人推荐这几道题的顺序：35 -> 34 -> 33 ) 
  
例题[35 Search Insert Position](https://leetcode.com/problems/search-insert-position/)  
这道题有一个地方需要注意，题目要求在查找失败时返回插入位置，由于查找失败时 ST[high] < key, ST[low] > key, 因此，**key的插入位置为low**.  
  
***  
例题[34 Search for a Range](https://leetcode.com/problems/search-for-a-range/)完全是35题的应用。  
  
*** 
例题 [33 Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) 算是一道比较复杂的二分查找的题，算是二分查找的变形(上面提到二分查找限于有序序列)。详细的过程分析可以参考[pezy](https://github.com/pezy/LeetCode/tree/master/058.%20Search%20in%20Rotated%20Sorted%20Array).  









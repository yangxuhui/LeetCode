这道题在*Programming Pearls*(**《编程珠玑》**)第二章中有比较深入浅出的讨论，如果有时间，**一定要读一读**。    
   
这道题用到**Signature**方法。我们需要用一个共同的特征来表示anagrams，对于任意一个字符串，对其进行排序（以字典序），得到的结果即其signature。比如：pots, stop, tops，其signature为opst。   
   
剩下的部分就简单了，将数组中所有的字符串按其signature分组。      
   
当然这道题挺怪的，表述不是很清楚，不理解题意可以参考[这里](https://leetcode.com/discuss/215/does-return-groups-return-result-vector-string-return-groups),简单来说就是让我们返回所有包含2个以上anagram的字符串。

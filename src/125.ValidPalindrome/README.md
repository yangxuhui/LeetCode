这道题是一道思路相对直接简单的题，难度为Easy，只是不知道为何通过率会这么低。   
   
首先思路一：可以将字符串中所有非数字和字母的字符去掉，然后判断是否为[回文](http://baike.baidu.com/link?url=TOoFPHQ1eC_ZtQVJF7_11ovE2ekVPvf90n9gjpKj3Yp8PDBe7ui3J9uA5L0dmvlhzNhC8BDSr8BUL_mrRF66z_)。   
   
思路二：遇到非数字和字母的字符跳过，判断字母和数字是否为回文   
   
***
这道题我的收获包括：   
* **cctype** 头文件中包括判断和处理字符的方法
* 题目中的提示对于面试很重要，即在面试官没有对题目一些细节说明时，不要自己猜，要主动提问。具体到这道题，题目认为空字符串也属于回文
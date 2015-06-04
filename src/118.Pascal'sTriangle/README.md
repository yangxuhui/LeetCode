[杨辉三角](http://baike.baidu.com/link?url=X5ohrJNjhf206CUcwDzlncZlicilU0b3Kpmn6GBuDvjIb_uHMQMPTMQnVXp8G5BAvpt0KeJ23Bj-g9IkacBCv_)是一个简单又复杂的概念。具体概念及其应用可以参考百度百科或维基百科的介绍。
   
这道题让我们生成给定行数的杨辉三角，只需要根据其规律用程序设计语言表示出来。
***
先直接表述规律：
1. 第一行为1，第二行为1,1
2. 从第三行开始，首尾均为1，该行下标为i的元素值 = 上一行下标i-1的元素值 + 上一行下标i的元素值，其中，0 < i < 行号-1（这里默认下标从0开始）
   
用代码表示为：
```cpp
vector<vector<int>> generate(int numRows) {
  vector<vector<int>> ret;
  for (int i = 0; i < numRows; ++i) {
    vector<int> v;
    if (i == 0) {
      v.push_back(1);
    } else if (i == 1) {
      v.push_back(1); v.push_back(1);
    } else {
      v.push_back(1);
      for (int j = 1; j < i; ++j)
        v[j].push_back(ret[i-1][j-1] + ret[i-1][j]);
      v.push_back(1);
    }
    ret.push_back(v);
  }
  return ret;
}
```
上面的代码就是直接将规律表述出来，思路简单，但是代码有点冗长。可以简化一下，[这里](https://github.com/yangxuhui/LeetCode/blob/master/src/118.Pascal%27sTriangle/Pascal%27sTriangle.cpp)是我简化之后的版本。   
   
比较奇怪的是简化的版本执行时间一直是4ms，而上面的版本运行时间是0ms，有人知道为什么吗？

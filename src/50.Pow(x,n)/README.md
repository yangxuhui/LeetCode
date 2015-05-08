求幂是**Divde and Conquer(分治法)** 的应用之一。  
   
主要思路是：  
```cpp
if (n == 0) return 1;
else if (n % 2 == 0) return square(pow(x, n/2)); // n is even
else return x * pow(x, n - 1); // n is odd
```
   
这里有几个地方需要注意：  
  
* 这个算法的时间复杂度为**O(logn)**
* 注意n为偶数时，需要使用square函数（自定义），或者可以将pow(x, n/2)的值保存下来（设为tmp）并写为tmp * tmp。 注意这个很重要，如果写成pow(x, n/2) * pow(x, n/2),算法的时间复杂度就变成O(n)  
* 上面的写法要求 n 为正数，因为n为奇数时，返回的是x * pow(x, n-1)，若n为负数，则会导致runtime error  
   
***  
由于我使用上面算法，对n为负数时，需要额外的处理，即对n取绝对值，求pow(x, abs(n)), 取倒数。  
  
这里有一个非常容易出错的地方：**对一个整数取绝对值时要考虑INT_MIN**，用int 来表示abs(INT_MIN)会overflow，可以用unsigned int 解决。  
***  
我看了一下[pezy](https://github.com/pezy/LeetCode/tree/master/082.%20Pow%28x%2C%20n%29)的做法，有几个地方值得学习：
   
* n 为奇数时，可以利用x * square(pow(x, n/2)) 这样，n 为负数就可以解决了

两数相除，不能用 *, /, %, 只剩 + 和 - 运算(显然我的武器库里还没有 >>, << 运算)。  
  
第一直觉只能想到每次用 dividend - divisor 直到 dividend < divisor， - 操作的次数就是相除结果。显然，这样做在遇到大数除小数时会超时(例如-2147483648 / 2)。  
  
再想，如果两个数的位数一样，那么上面的方法时间就会减少，所以可以考虑我们做除法的过程，第一次肯定是用前面与除数相同位数的数与除数相除(假设dividend > divisor, dividend < divisor 时结果为0)，之后用前面相除的余数 * 10 + 下一位数字与除数相除，重复这个过程直到最后一位数。  
  
具体到实现，可以考虑 string 与 int 的相互转换(C++ string 类的 Numeric Conversions 《C++ Primer 5th》 9.5.5):  
  
第一步：  
```cpp
result = to_string(getQuotient(stoi(sdividend.substr(0, sdivisor.size())), divisor, rem));
```
result用来保存相除的结果，sdividend, sdivisor 分别为dividend 和divisor 转换为string 后的结果，getQuotient函数用除数，被除数，上次相除的余数做为参数，返回相除结果，第一步得到dividend前divisor.size()位除以divisor的结果(dividend,divisor 均为正数，结果的符号问题可以在开始时判断)，这个结果可能为0，但是不影响。  
  
循环：  
```cpp
result += to_string(getQuotient(stoi(to_string(rem).append(sdividend, j, 1)), divisor, rem));  
```  
  
每次用append 将上次相除的余数和下一位拼接起来做该次循环的除数，知道最后一位完成。  
  
这样做之后，发现了许多没有考虑到的边界情况， 当dividend 或divisor为INT_MIN 时，不能用abs转换为正数(溢出), 之后花了很多很多时间来一一排除边界情况(基本证明这种方法是不合适的，浪费了好多好多时间)，看我的代码可以发现用if做了很多边界情况的判断。  
  
虽说浪费时间一一排除了边界情况，但还是有一些收获的，比如，dividend == INT_MIN 时，由于无法用-dividend 来做运算，所以还要单独为这种情况写逻辑，具体实现时发现非常困难。最后想到，先用divdend + abs(divisor)，之后就可以用上面的逻辑进行处理了(abs(dividend)不溢出了)，只是在返回结果时要注意，前面已经除了一个divisor了(divdend + abs(divisor))，所以这种情况下要对结果+1。  
   
特别麻烦，特别浪费时间的排除边界情况之后(当然，我的智商还不足以想到所有的边界情况，只能不断提交来得到通不过的边界情况)，终于AC了，时间一次24ms，一次40ms，证明这种解法是一种低效且不优雅的解法。  
  
***

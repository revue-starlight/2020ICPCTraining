# 字符串第一周
### 学习内容

如何使用字符串
在c++中，string内置了许多成员函数。本周学习如何使用相应的函数

1.长度
---

·s.length() 用来求取字符串的长度
·s.size()与s.length()无任何区别，只是名字不同
时间复杂度都是O(1).
2.增删改减
---

#####  s.append()
s.append(str);
s.append(str,x,y);
s.append(s.begin(),s.end());
在后方接字符串

    string s
    s.append("abc");//此时 s=="abc"
    
    //开始+长度
    string s1="123abc456def";
    s.append(s1,3,4);//从下标为3的字符开始截取长度为4的字符串
    //此时s=="abcabc4"
    
    //给出首尾下标
    string s2="ABCDEF114514"
    s.append(s2.begin()+2,s2.end());//从下标为2到结束
    //此时s=="abcabc4CDEF114514"
    

时间复杂度: O(视被截取的字符串的长度而定)

##### s.insert()
s.insert(1,str,3,4);
从下标为1的字符后面开始插，也就是下标为1和2中间insert，插入str的下标为3开始，长度为4的字符串。
↑这是最方便的方法
时间复杂度: O(视被截取的字符串的长度而定)

#### s.erase()
s.erase(10,8)下标为10开始删8个
s.erase(s.begin()+9)删一字符就这么删 下标为9的那个被删了
s.erase(s.begin()+5,s.end()-9)
删除区间为[s.begin()+5,s.end()-9]（也就是从后往前数第10个）
时间复杂度O(n)


#### s.clear()
O(1)，放心使用

3.查找与交换
---
s.find()
朴素查找，瞬间爆炸
AC自动机，请看下集
s.swap()
str1.swap(str2);
这样两个就交换了
时间复杂度O(1)。
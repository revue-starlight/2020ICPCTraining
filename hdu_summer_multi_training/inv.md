# 乘法逆元
(a+b) % p = a%p + b%p<br/>
(a*b) % p = a%p * b%p<br/>
(a-b) % p = a%p - b%p<br/>
a^(p-1) % p = 1 % p<br/>
a * a^(p-2) = 1 % p<br/>
<br/>

a对于%p的乘法逆元是 a^(p-2)

a/b % p == a * (b^(p-2)) % p

https://blog.csdn.net/oampamp1/article/details/107508328

x^2 == n (%p)<br\>
⬇<br\>
x == 根号n (%p)<br\>
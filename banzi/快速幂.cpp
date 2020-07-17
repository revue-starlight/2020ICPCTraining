int pow_mod(int a ,int b)
{
     int ans = 1 ;
     int base = a % c;
         while(b>0)
     {
           if(b&1!=0) ans = (ans *base)%c;
    　　　　 base = (base*base)%c;
    　　　　 b >>= 1;
　　}
     return ans;
}
#https://codeforces.com/problemset/problem/1325/D

Given u and v
We need to find an array such that bitwise X-OR of all its elements are u and sum of all its elements are v.

  
The following statement holds for any a and b.
u=a^b
v=a+b

a + b = a ^ b + 2 * (a & b)  
  
Why is a + b = a ^ b + 2 * (a & b) true? 

a ^ b is add without considering the carries. So in order to get a + b from a ^ b we need to take the
missing carry part into account. When does carry happen? Exactly when a[k] == b[k] = 1. So we basically 
left out 2 equal part of indices where a[i] == b[i] = 1, which is exacly 2 * (a & b).
  

1.If u>v and u%2!=v%2 then the answer is -1
2.So if u==v and u==0 then the answer is 0
and the rest condition are given in the code
 
 
 
 
 
 
 
 
 
 
 u= xor
 v= sum
 **************************
 if u=2 =010
    v=4 =100
   
   a=3=11
   b=1=01
   xor=10=2
   and 3+1=4
   so this is working
********************************   
 if u=1 =  01
    v=3 =  11
   
   so 1 1 1
   xor=1
   and sum=1+1+1=3
   so this is working
   
   note: if we have even number of one's then the xor will be 0 else 1.
********************************
   if u>v 
   u=8= 1000
   v=5= 0101
   it's not possible because if we notice the left most bitfor 8 it is 1 and for 5 it is 0
   if the left most bit of the sum is 0 that means there is no element in the array which have 1 in the leftmost position
   but in the xor we can see that leftmost digit equal to 1. SO we can say that u will always be 
   less than v meaning xor will be always less then the sum.
   So if U is greater than v then the output will be -1.
***************************************************************
 if u=8 = 1000
    v=13  1101
       a1 ----1
       a2 ----1
       a3 ----0
       xor=---0
       sum=---0
   so for all the elements of the array if there is an even mber of 1 then the rightmost bit in the xor will be zero and 
   rightmost bit int he sum will also be 0 .
   and if odd number of one's then the rightmost bit in the xor will be 1 in the xor and sum.
   so we can say that u and v both will have to be odd or both will have to be even.
     means u%2==v%2 , this condition must be satisfied other wise we will print -1 as the answer.
**************************************************************************************************************
     if u==0 and v==0
      then we can print two elements as a=0 and b=0
 ************************************************************************************************
   if we want output one element then the following contidtion must be hold:
       if u==v and u>0 and v>0
     then we will have answer just 1 and it is u
**********************************************************************
if we want output more than 1 elements than the follwoing condition must be hold:

x=(v-u)/2   [u,x,x]
so we can see that in the xor x and x will be zero and final xor will be u and sum v= u+x+x
***********************************************************************
suppose we take two numbe a and b
u=a @ b
v=a + b
a+b: 0 0 = 0 --> same as a @ b= (a @ b) + 2 x(a & b)
     0 1 = 1---> same as a @ b= (a @ b) + 2 x(a & b)
     1 0 = 1----> same as a @ b= (a @ b) + 2 x(a & b)
     1 1 = 1-----> same as 2x(a&b)= (a @ b) + 2 x(a & b)
  so we can say that a+b=(a@b) + 2x(a&b)
  so v=u + 2*(a@b)
  so a&b=(v-u)/2;
*************************************************************************************************
#include<bits/stdc++.h>
using namespace std;

int main()
{
        long long int u,v;
        cin>>u>>v;
        if(u > v || u % 2 != v % 2)
        {
             cout<<-1<<endl;
        }
        else if(u == v)
        {
            if(u == 0)
            {
                 cout<<0<<endl;
            }
            else
            {
                cout<<1<<endl;
                cout<<u<<endl;
            }
        }
        else
        {
            long long int x= (v - u) / 2;
            if((u & x)!= 0)
            {
                cout<<3<<endl;
                cout<<u<<" "<<x<<" "<<x<<endl;
            }
            else
            {
                cout<<2<<endl;
                cout<<(u+x)<<" "<<x<<endl;
            }
        }
}

So first observe that the subsequence 
can't contain any element that isn't coprime with 𝑛. Why? Because then its product 
won't be coprime with 𝑛, so when you take it modulo 𝑛, it can't be 1. In mathier words,
𝑔𝑐𝑑(𝑝𝑟𝑜𝑑 𝑚𝑜𝑑 𝑛,𝑛)=𝑔𝑐𝑑(𝑝𝑟𝑜𝑑,𝑛)≠1. Now, let's take all elements less than 𝑛 and coprime with it,
and let's look at their product modulo 𝑛; call it 𝑝. If 𝑝 is 1, you can take all these elements. 
Otherwise, you should take them all except for 𝑝. It belongs to them because 𝑝 is coprime with 𝑛.





#https://codeforces.com/contest/1514/problem/C
  
  
  
  #include <bits/stdc++.h>
using namespace std;
bool ok[100005];
int main()
{
    int n;
    scanf("%d",&n);
    long long prod=1;
    int  cnt=0;
    for (int i=1;i<n;i++)
    {
        if (__gcd(n,i)==1)
        {
            ok[i]=1;
            cnt++;
            prod=(prod*i)%n;
        }
    }
    if (prod!=1){
        cnt--;
        ok[prod]=0;
    }

    cout<<cnt<<endl;
    for (int i=1;i<n;i++)
    {
        if (ok[i])
         cout<<i<< " ";
    }
    cout<<endl;
}


















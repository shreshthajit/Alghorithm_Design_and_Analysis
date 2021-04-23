
#https://codeforces.com/contest/1496/problem/C
In this problem there will be n miner and n diamond mine and each miner will mine each diamond mine.
And the required energy is the distance of miner and mine.We need to minimize the energy.
In Y axis there will be the miner and in the x axis there will be the diamond mine.

We can see that the diamond mine and miner in the negative x and y axis can be transfer in the positive x and y axis
because the distance will not be changed.And then we will take two array one for miner and other for mines and
we will sort the array.
  
For example, if you match 𝐴(𝑎1,0) with 𝐵(0,𝑏1), 𝐶(𝑎2,0) with 𝐷(0,𝑏2), the answer will be |𝐴𝐵|+|𝐶𝐷|; if you match 𝐴 with 𝐷 and
𝐵 with 𝐶, the answer will be |𝐴𝐷|+|𝐵𝐶|<|𝐴𝑂|+|𝐷𝑂|+|𝐵𝑂|+|𝐶𝑂|=|𝐴𝐵|+|𝐶𝐷|.we can see this prove from the tutorial section.
  
So we sort the array X and y and then calculate the distance each element of x corresponding to the each y element
then we will find a minimized energy.
  
-----------------------------------------------------------------------------------------------------------------------------  
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int X[n+1],Y[n+1];
        int a=0,b=0;
        for(int i=0; i<2*n; i++)
        {
            int x,y;
            cin>>x>>y;
            if(x==0)
                Y[b++]=abs(y);
            if(y==0)
            {
                X[a++]=abs(x);
            }
        }
        sort(Y,Y+b);
        sort(X,X+a);
        double ans=0;
        for(int i=0;i<n;i++){
            ans=ans+sqrt(1.0*X[i]*X[i]+1.0*Y[i]*Y[i]);
        }
         printf("%.15lf\n",ans);

    }

}










#https://codeforces.com/contest/1420/problem/B


In this problem we need to find such pair so that the bitwises AND is greater than or equal to X-OR of that pair.
  
we take two number
1000
0101
we can clearly see that the most significant bit which is 1 situated in the left so if we do XOR it will clearly be greater than
of it's AND.

1100
1000
we cal see that the bitwise AND will be greater than the XOR of this two element.
 
  
So if we observe the fact that  if we take some number like 5,6,7 and take it's most significant bit number which is 4 and
then we can make pair with (4,5),(4,6),(4,7) because if we represent them in binary number then we will notice that it will
gave us always bitwise AND greater than XOR because both of the number of pairs have 1 as a most significant bit.
If we take 3 and 4 then we will find XOR is greater than AND. And so for every number in the array we will take it's most
significant bit number and those number which are belong to the same significant number will form pair And thus we will get
out answer.
-- ---------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long  n;
        cin>>n;
        long long  a[n+1];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        long long  b[35]= {0};

        for(int i=0; i<n; i++)
        {
            long long  p=a[i],c=0;
            while(p>0)///we are calculating most significant bit for every number of the array.
            {
                p=p/2;
                c++;
            }
            b[c]++;
        }
        long long  ans=0;
        for(int i=0; i<=32; i++)
        {
            if(b[i]>=2)
            {
                ans+=(b[i]*(b[i]-1))/2;
            }
        }
        cout<<ans<<endl;
    }
}























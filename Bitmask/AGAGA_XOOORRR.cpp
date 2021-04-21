

We can take two adjacent elements and replece them with their xor so the length will decrease by 1.
we have to make all the elements of the array equal.
  
we know some important xor properties:

A ^ A = 0
0 ^ A = A

A ^ B ^ C ^ B ^ C ^ A ^ D = A ^ A ^ B ^ B ^ C ^ C ^ D
                          =0 ^ 0 ^ 0 ^ D
                          =D
                          
so we can say that if the sum of all elements is zero so the answer is yes.
  if the sum is not zero then we will iterate through the array doing xor and check weather there is a i where those xor is
  equal to sum and if the number of such partition is greater then two then it can be said that there exist an answer where
  the array can be qualized.


for example 
1 2 3 1
xor_sum=1
 
 here 2 and three gives us 1 and so the answer is yes.



---------------------------------------------------------------------------------

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int T,n,m;
int a[20010];
int main()
{

    scanf("%d",&T);
    while(T--)
    {
        int cd=0,num=0;
        m=0;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            m=m^a[i];
        }
        if(!m)printf("YES\n");
        else
        {
            for(int i=1; i<=n; i++)
            {
                cd=cd^a[i];
                if(cd==m)
                {
                    cd=0;
                    num++;
                }

            }
            if((cd==m||cd==0)&&num>=2)printf("YES\n");
            else printf("NO\n");
        }
    }

}


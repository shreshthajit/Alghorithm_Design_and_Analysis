#include<bits/stdc++.h>

using namespace std;

int main()
{

    long long  n;
    cin>>n;
    long long w[n+1],sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>w[i];
        sum+=w[i];
    }
    long long ans=sum;

    for(int mask=0;mask<(1<<n);mask++){
        long long sm=0;
        for(int j=0;j<n;j++){
            if(mask&(1<<j)){
                sm=sm+w[j];
            }
        }
        long long diff=abs(2*sm-sum);
        if(ans>diff){
            ans=diff;
        }
    }
    cout<<ans<<endl;
}

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


        int segment;

        cin>>segment;

        int arr[n];

        int mx_sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }



        for(int i=0; i<segment; i++)
            mx_sum=mx_sum+arr[i];

        int left=0;
        int right=segment;
        int tsum=mx_sum;

        for(int i=1; i<=n-segment; i++)
        {
            tsum=tsum-arr[left];
            tsum=tsum+arr[right];
            left++;
            right++;
            mx_sum=max(mx_sum,tsum);
        }

        cout<<mx_sum<<endl;
    }


}


#https://codeforces.com/contest/276/problem/C


This problem says we need to maximum the total sum in those given range.
and for this we need to sort the array in such a way that the repeated range will find the maximum value from the array.
  
so we will first sort the array.
next we will take the range form the input and from the range we will use an array called query which will count the frequency
of the range in a way like we will increse the left one and decrease the one after right.because the next step we will use 
for cummulative sum which will help us for not counting the the value r+1 in the query twice.
 
for example suppose we have the input given below.
5 3
5 2 4 1 3
1 5
2 3
2 3

index------> 1 2 3 4 5
array------> 1 2 3 4 5
 query-----> 1 2 0 -2 0
 we can see that we have counted 1 one times.2 two times and decreased (3+1)=4 by two times.because when we will use 
 cummulative sum this -2 will increse by the 3 and remain 1 by the previous sum. so there is a nutralized situation we can see
 
  
cum query---->1 3 3 1 1
sort--------->1 1 1 3 3
  
 
  suppose we take an another input and it is given below.
  6 2
  1 2 3 4 5 6
  1 2
  5 6
index------> 1 2 3 4 5 6
array------> 1 2 3 4 5 6
query------> 1 0 -1 0 1 0

cum query--->1 1 0 0 1 1
  so we can see that when the sum is reaching at index 3 it is getting zero and doing the next step.so if there is any
  previous value without zero that means that there is an intersection in those segment and thus we need to add the
  previous frequency to the current frequency.
    
    
    
    
   
    
  suppose we take an another input and it is given below.
  6 3
  1 2 3 4 5 6
  1 2
  2 4
  5 6
    
 index----> 1 2 3 4 5 6
 array----> 1 2 3 4 5 6
 query----->1 1 -1 0 0 0
 cum sum--->1 2 1 1 1 1
  
    
    
----------------------------------------------------------------------------------------------------------------------------------------

    
    
    
    
 #include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    int i=0;
    long long int a[n];
    for(i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    long long int query[n+1];
    memset(query,0,sizeof(query));

    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(b!=n)
        {
            query[a]++;
            query[b+1]--;
        }
        else
        {
            query[a]++;
        }
    }

    for(i=1; i<=n; i++)
        query[i]+=query[i-1];

    sort(query+1,query+n+1);

    long long int sum=0;

    for(i=0; i<n; i++)
    {
        sum=sum+query[i+1]*a[i];
    }

    cout<<sum;
}

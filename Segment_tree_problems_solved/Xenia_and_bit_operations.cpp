#include<bits/stdc++.h>

using namespace std;

const int N=102355;

int arr[4*N];
struct segment
{
    int data;
    int level;
} seg [4*N];


void build(int low,int high,int node)
{
    if(low>high)
        return;

    if(low==high)
    {
      seg[node].data=arr[low];
      seg[node].level=1;
      return;
    }
    int mid=low+high>>1;

    build(low,mid,2*node+1);
    build(mid+1,high,2*node+2);

    seg[node].level=seg[2*node+1].level+1;

    if(seg[node].level & 1)///here we are checking if the seg[node].level is odd or not
    {
       seg[node].data=seg[2*node+1].data ^ seg[2*node+2].data;
    }
    else
    {
    seg[node].data=seg[2*node+1].data | seg[2*node+2].data;
    }
}

void  update(int low,int high,int index,int value,int node){

 if(low>high)
 return;

 if(low==high)
 {
   seg[node].data=value;
 }
 else{

 int mid=low+high>>1;
 if(index>=low && index<=mid)
 update(low,mid,index,value,2*node+1);
 else
 update(mid+1,high,index,value,2*node+2);

  if(seg[node].level & 1)
  {
    seg[node].data=seg[2*node+1].data ^ seg[2*node+2].data;
  }
  else{
  seg[node].data=seg[2*node+1].data | seg[2*node+2].data;
  }
 }

 }



int main()
{

    int m,n;
    cin>>n>>m;
    int i;
    int digit=pow(2,n);

    for(i=0;i<digit;i++)
    cin>>arr[i];


    build(0,digit-1,0);


    for(i=0;i<m;i++){
    int b,p;
    cin>>b>>p;
    update(0,digit-1,b-1,p,0);
    cout<<seg[0].data<<endl;
    }


}

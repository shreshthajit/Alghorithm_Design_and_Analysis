#include<bits/stdc++.h>



using namespace std;
#define mx 1000
int lis[mx];
int arr[mx]={10,22,9,11,33};
int n=5;
void LiAlternatingEvenOdd(){
      bool temp=arr[0]%2;
      bool first=true;
    for(int i=1;i<n;i++){

        for(int j=0;j<i;j++){

                if(arr[i]>arr[j] && (abs(arr[i]-arr[j]))==1 ){
                    lis[i]=max(lis[j]+1,lis[i]);

                }


        }
    }


}
int main(){
     n=5;
  //  //cin>>n;
    //for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        lis[i]=1;
    }

//    for(int i=1;i<n;i++){
//            for(int j=0;j<i;j++){
//                if(arr[i]>arr[j]){
//                        lis[i]=max(lis[j]+1,lis[i]);
//
//                }
//            }
//
//    }

LiAlternatingEvenOdd();

    for(int i=0;i<n;i++)cout<<lis[i]<<" ";



return 0;
}

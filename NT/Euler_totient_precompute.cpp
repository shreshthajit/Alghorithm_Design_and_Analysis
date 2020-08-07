#include<bits/stdc++.h>

using namespace std;
#define mx 100005
int phi[mx];

void euler_totient() {
    for(int i=0; i<mx; i++) phi[i]=i;
    for(int i=2; i<mx; i++) {
        if(phi[i]==i) {
            for(int j=i; j<mx; j+=i)
                phi[j]-=(phi[j]/i);
        }
    }
}
int main(){

  euler_totient();
  for(int i=0;i<mx;i++)
  cout<<phi[i]<<" ";

}

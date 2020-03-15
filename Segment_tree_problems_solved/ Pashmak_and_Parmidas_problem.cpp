
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <map>
using namespace std;

int L[1000003], R[1000003], a[1000003], segtree[4000005];
int N;



void update(int p, int L, int R, int S){
    if(R<S || S<L)return;
    if(L==R && R==S){
        segtree[p]++;
        return;
    }
    int M=(L+R)/2;
    update(2*p,L,M,S);
    update(2*p+1,M+1,R,S);
    segtree[p] = segtree[2*p]+segtree[2*p+1];
}



int rmq(int p,int L,int R,int S,int T){
    if(S>T)return 0;

    if(R<S || T<L)return -1;

    if(S<=L && R<=T)return segtree[p];

    int M=(L+R)/2;
    int left=rmq(2*p,L,M,S,T);
    int right=rmq(2*p+1,M+1,R,S,T);

    if(left<0)return right;
    if(right<0)return left;

    return left+right;
}

int main(){

    map<int,int> st;

    scanf("%d", &N);

    for(int i=0;i<N;++i){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<N;++i){
        st[a[i]]++;

        L[i] = st[a[i]];
        cout<<"L[i]="<<L[i]<<" ";
    }
    cout<<endl;
    st.clear();


    for(int i=N-1;i>=0;--i){
        st[a[i]]++;
        R[i] = st[a[i]];
        cout<<"R[i]="<<R[i]<<" ";
    }
    cout<<endl;



    long long ans = 0;
    for(int i=N-1;i>0;--i){
        update(1,1,1000000,R[i]);
        ans+=rmq(1,1,1000000,1,L[i-1]-1);
    }
    cout << ans << endl;
    return 0;
}

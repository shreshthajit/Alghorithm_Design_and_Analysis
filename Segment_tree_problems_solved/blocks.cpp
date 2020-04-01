#include <bits/stdc++.h>
#define MAX 2000001
#define left  (2*i+1)
#define right (2*i+2)
#define mid ((l+r)>>1)


using namespace std;

int seg[MAX],lazy[MAX];


int clear_lazy(int i)
{
    lazy[left] = lazy[right] = lazy[i];
    seg[i] = lazy[i];
    lazy[i] = 0;
    return 0;
}



int update(int i,int l,int r,int x,int y,int v)
{
    if(lazy[i]) clear_lazy(i);

    if (l>r || y<l || x>r) return 0;

    if(l>=x && r<=y)
    {
        seg[i] = v;
        lazy[left] = lazy[right] = v;
        return 0;
    }
    update(left,l,mid,x,y,v);
    update(right,mid+1,r,x,y,v);
    seg[i] = max(seg[left],seg[right]);
    return 0;
}








int query(int i,int l,int r,int x,int y)
{
    if (lazy[i]) clear_lazy(i);

    if (l>r || y<l || x>r) return 0;

    if (l>=x && r<=y) return seg[i];

    return max(query(left,l,mid,x,y),query(right,mid+1,r,x,y));
}








int main()
{
    int n;
    cin >> n;


    for(int i=0; i<n; i++)
    {
        int l,h,p,c,x;


        cin >> l >> h >> p >> c >> x;


        int mx = query(0,0,200000,x,x+l-1);

        cout<<"mx= "<<mx<<endl;


        if(c)///done....we will take a pillar and take one pillar onto the other
        {
            update(0,0,200000,x,x+l-1,mx+1);
            update(0,0,200000,x+p-1,x+p-1,mx+1+h);
        }
        else///i think here we will take only one pillar for the downward connection and it may be the largest one
        ///and so we will compare it with the previous value of the downshape pillar
        {
            int qp = query(0,0,200000,x+p-1,x+p-1);///we are searching the maximum value in that point
            if (mx>=h+qp) update(0,0,200000,x,x+l-1,mx+1);
            else update(0,0,200000,x,x+l-1,qp+h+1);
        }
    }



    cout << seg[0] << endl;
    return 0;
}

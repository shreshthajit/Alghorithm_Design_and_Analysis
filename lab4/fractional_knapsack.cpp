#include<bits/stdc++.h>




///input
///   value amoutn  price
  /// 120    30       4
  /// 100    20       5
   ///60     10       6
   ///40     5        8


using namespace std;


struct item
{
    int value;
    int amount;
    int unit;
};


bool cmp(struct item a,struct item b)
{

      int  r1=a.value/a.amount;
      int  r2=b.value/b.amount;
     return r1>r2;
}
int main()
{
    //vector<item>table;
    struct item ara[100];

    int bag;
    cin>>bag;

    for(int i=0;i<4;i++)
    {
        cin>>ara[i].value;
        cin>>ara[i].amount;
        ara[i].unit=ara[i].value/ara[i].amount;
    }
    sort(ara,ara+4,cmp);

    int profit=0;
    for(int i=0;i<4;i++)
    {
        if(bag<=0)
            break;
    profit=profit+min(bag,ara[i].amount)*ara[i].unit;

    cout<<"value="<<ara[i].value;
    cout<<"  amount="<<ara[i].amount;
    cout<<"  unit="<<ara[i].unit;
    cout<<"  taken amount="<<min(bag,ara[i].amount)<<endl;

    bag-=min(bag,ara[i].amount);
    }

    cout<<profit;
}

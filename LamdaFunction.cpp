#include <bits/stdc++.h>
using namespace std;


int main()
{
    /*
    int a[]= {4,5,6};
    cout<<a;//this will show the index of a[0] and if print a+1 then we will find the location of next value where memory will increase by 4.

    cout<<*a; //this will show us 4 which is the value of a[0]
    cout<<*(a+1)<<endl;//this will show us 5 which is the value of a[1];

    int *b=new int[10];//this is same as array and we can iterate through it
    for(int i=0;i<10;i++)
        b[i]=i;
    for(int i=0;i<10;i++)
        cout<<b[i]<<" ";

    b=new int[20];//so if we use pointer array we can resize this array.

    sort(a,a+n);///here we are passing pointer and they are a[0] and a[n];

    for(int *i=a;i!=a+5;i++)///here i is pointing to the head of the array.
        cout<<*i<<" ";
        */

    ///lamda function
    ///In lamda function we treat function as variable

    auto func=[](int i,int j)
    {
        return i+j;
    };

    function  <int(int,int)> check=[](int i,int j) ///so in this function we will write first the return type in the angle bracket and then the argument's type
    {
        return i*j;
    };

    cout<<func(20,30)<<endl;
    cout<<check(10,10)<<endl;

    int var=0;
    int tmp=10;
    auto increase=[&](int val)///here & helps us to access all the global variables.
    {
        var +=val;
        tmp +=val;
    };

    increase(10);
    increase(20);

    cout<<var<<" "<<tmp<<endl;

    function <int(int)> fib=[&fib](int i)///here &fib is capturing fib function
    {
        if(i<=1)
            return 1;
        return fib(i-1)+fib(i-2);
    };
    cout<<fib(10)<<endl;



    ///a good use of lamda function is in sorting

    int ara[6]= {1,2,3,4,5};
    sort(ara,ara+5,[](int i,int j)
    {
        return i>=j;
    });

    for(int i=0;i<5;i++)
        cout<<ara[i]<<" ";
    cout<<endl;

}







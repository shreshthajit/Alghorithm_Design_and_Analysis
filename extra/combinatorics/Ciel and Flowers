

so if any number divides properly by 3 then there is a problem we can make more ans 
like 8 8 9
so ans=2+2+3=7 but the ans is 8
because if we take 2+2+2 then r=2 g=2 and b=3 so we can add plus one in the answer and the ans is 8

//////////////////////////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long a[4];
	cin>>a[0]>>a[1]>>a[2];

	long long ans=a[0]/3+a[1]/3+a[2]/3;
	if(a[0]==0 || a[1]==0 || a[2]==0)
        cout<<ans<<endl;
    else{
	a[0]%=3;
	a[1]%=3;
	a[2]%=3;
	sort(a,a+3);
	if(a[0]==0 && a[1]==2){//for the test case 8 8 9
        ans++;
	}
	else{
        ans=ans+a[0];
	}
	cout<<ans;
    }
	return 0;
}

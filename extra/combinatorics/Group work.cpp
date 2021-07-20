We know that 
nc1+nC2+------nCn=2^n - 1
so nC2+nC3+.....nCn=2^n -1 - n;
because we have to choose at least 2 students so we can do this by the above method.
-----------------------------------------------------
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	 int n;
	 cin>>n;
	 long long ans=1;
	 for(int i=0;i<n;i++){
        ans=ans*2;
	 }
	 cout<<ans-1-n<<endl;
	 
}

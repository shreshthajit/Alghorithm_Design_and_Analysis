#include<bits/stdc++.h>
using namespace std;
vector<int> calculateZ(string inp)
{
    int len = inp.length();
    vector<int> Z(len);
    int left = 0;
    int right = 0;
    for(int k = 1; k < len; k++)
    {
        if(k > right)
        {
            left = right = k;
            while(right < len && inp[right] == inp[right-left])
            {
                right++;
            }
            Z[k] = right - left;
            right--;
        }
        else
        {
            int k1 = k - left;
             
            if(Z[k1] < right-k+1)
            {
                Z[k] = Z[k1];
                
            }
            else
            {
                left = k;
                while(right < len && inp[right] == inp[right-left])
                {
                    right++;
                }
                Z[k] = right-left;
                right--;
            }
        }
    }
    return Z;
}
int main()
{
    string s;
    cin >> s;
    vector<int> Z = calculateZ(s);
    for(int i=0;i<Z.size();i++)
    cout<<Z[i]<<" ";
    cout<<endl;
}

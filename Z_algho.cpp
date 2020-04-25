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
            // inside the Z-Box
            if(Z[k1] < right-k+1)
            {
                Z[k] = Z[k1];
                //if the value is inside the Z-box then copy it
            }
            else
            {
                // otherwise do more comparisons
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
    // Z[i] denotes the length of the longest substring starting from i which is also the prefix of the string.
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

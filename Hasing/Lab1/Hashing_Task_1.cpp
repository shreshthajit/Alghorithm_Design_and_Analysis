 #include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, a;

    vector<long long> table[100000];

    int key = 0, radix, index, mod_num = 100000+1, count = 0;
    bool found = false;

    cout<<"Enter the string:"<<endl;

    getline(cin, s);

    cout<<"Enter the value of radix:"<<endl;

    cin>>radix;

    for(auto &x : s)
        if(x == ',' || x == '.' || x == '!' || x == ':' || x == ';')
            x = ' ';

    // cout<<"-->> "<<s<<endl;    

    stringstream str(s);

    while(str>>a)
    {
        key=0;
        long long p=1;
        // cout<<"-"<<a<<endl;
        for(int j = 0; j<a.size(); j++)
        {
            key += ((int)a[j] *p)%mod_num;
            key%=mod_num;
            p*=radix;
            p%=mod_num;

        }
        index = key % mod_num;
        if(table[index].size() == 0)
        {
            table[index].push_back(key);
            count++;
        }
        else
        {
            for(auto y : table[index])
            {
                if(y == key)
                {
                    found = true;
                    break;
                }
            }
            if(!found)
            {
                table[index].push_back(key);
                count++;
            }
        }
    }

    cout<<"Word Count:  "<<count<<endl;

    return 0;
}

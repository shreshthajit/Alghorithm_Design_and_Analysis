
#include <bits/stdc++.h>

using namespace std;

struct elements
{
    int key;
    string value;
    int occurance = 0;
};


int main()
{
    string s, a;

    vector<elements> table[100000];

    int key = 0, radix, index, table_size = 100000+1,/* count = 0,*/ i, c1 = 2234, c2 = 13;
    bool found = false;

    cout<<"Enter the string:"<<endl;

    getline(cin, s);

    cout<<"Enter the value of radix:"<<endl;

    cin>>radix;

    for(auto &x : s)
        if(x == ',' || x == '.' || x == '!' || x == ':' || x == ';' || x == '\'')
            x = ' ';

    stringstream str(s);

    while(str>>a)
    {
        i = 0;
        key=0;
        long long p=1;
        for(int j = 0; j<a.size(); j++)
        {
            key += ((int)a[j] *p) % table_size;
            key %= table_size;
            p *= radix;
            p %= table_size;

        }
        index = key % table_size;
        while(1)
        {
            index = (index + i*c1 +i*i*c2) % table_size;
            /*index %= table_size;
            c1 *= i;
            c1 %= table_size;
            c2 = c2 * i * i;
            c2 %= table_size;*/
            if(table[index].size() == 0)
            {
                elements temp;
                temp.key = key;
                temp.value = a;
                temp.occurance = 1;
                table[index].push_back(temp);

                break;
            }
            else
            {
                if(table[index][0].key == key)
                {

                    table[index][0].occurance++;
                    break;
                }
                i++;
            }
        }
    }

    cout<<"Enter word to search: "<<endl;

    cin>>a;
    found = false;

    for(i=0; i<100000; i++)
    {
        if(table[i].size() != 0 && table[i][0].value == a)
        {
            found = true;
            break;
        }
    }

    if(found)
        cout<<"Number of occurances of "<<a<<" is: "<<table[i][0].occurance<<endl;
    else
        cout<<"Word not present!"<<endl;

    //cout<<"Word Count:  "<<count<<endl;

    return 0;
}

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
    //elements table[100000][1];

    int key = 0, radix, index, table_size = 100000+1,/* count = 0,*/ i;
    bool found = false;

    cout<<"Enter the string:"<<endl;

    getline(cin, s);

    cout<<"Enter the value of radix:"<<endl;

    cin>>radix;

    for(auto &x : s)
        if(x == ',' || x == '.' || x == '!' || x == ':' || x == ';' || x == '\'')
            x = ' ';

    // cout<<"-->> "<<s<<endl;

    stringstream str(s);

 ///h(x)=[h(x)+f(i)]%table_size;here f(i)=i
    while(str>>a)
    {
        i = 0;
        key=0;
        long long p=1;
        // cout<<"-"<<a<<endl;
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
            index = (index + i) % table_size;
            if(table[index].size() == 0)
            //if(table[index][0].occurance == 0)
            {
                elements temp;
                temp.key = key;
                temp.value = a;
                temp.occurance = 1;
                table[index].push_back(temp);

                /*table[index][0].key = key;
                table[index][0].value = a;
                table[index][0].occurance = 1;*/

                break;
            }
            else
            {
                if(table[index][0].key == key)
                {
                    /*elements temp;
                    temp.key = key;
                    temp.value = a;
                    temp.occurance = 1;
                    table[index].push_back(temp);
                    table[index].occurance++;*/
                    table[index][0].occurance++;
                    break;
                }
                i++;
                /*for(auto y : table[index])
                {
                    if(y.key == key)
                    {
                        found = true;
                        break;
                    }
                }
                if(!found)
                {
                    elements temp;
                    temp.key = key;
                    temp.value = a;
                    table[index].push_back(temp);
                    count++;
                    i++;
                }*/
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

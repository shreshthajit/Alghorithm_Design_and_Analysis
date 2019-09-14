#include<bits/stdc++.h>
using namespace std;






int Lis_consecutive_subsequence(int arr[],int n)
{
    int lis_arr[n+1];
    for(int i=0;i<n;i++)
    {
        lis_arr[i] = 1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && lis_arr[j]+1>lis_arr[i] && arr[i]-arr[j]==1)
            {
                lis_arr[i] = lis_arr[j]+1;
            }
        }
        cout<<"For elements "<<arr[i]<<" Lis(array) is : ";
        for(int k=0; k<n; k++)
        {
            cout<<lis_arr[k]<< " ";
        }
        cout<<endl;
    }
    int maxx = 0,ind=0;
    for(int i=0;i<n;i++)
    {
        if(lis_arr[i]>maxx)
        {
            maxx = lis_arr[i];
            ind = i;
        }
    }
    vector<int>v;

    int liscnt = maxx;
    int last_ind= 0;


    for(int i=ind;i>=0;i--)
    {
        if(lis_arr[i]==maxx)
        {
            if(maxx==1)
            {
                for(int k=0;k<=i;k++)
                {
                    if(arr[k]<arr[last_ind] && arr[last_ind]-arr[k]==1)
                    {
                        v.push_back(arr[k]);
                        maxx--;
                        break;
                    }
                }
            }
            else
            {
                v.push_back(arr[i]);
                maxx--;
                last_ind = i;
            }
        }
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        cout<<v[i]<<" ";
    }   cout<<endl;
    return liscnt;
}














int Lis_ALternative_odd_even_Sequence(int arr[],int n)
{
    int lis_arr[n+1];
    for(int k=0; k<n; k++)
    {
        lis_arr[k]=1;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j] && lis_arr[j]+1>lis_arr[i] && (arr[i]+arr[j])%2!=0)
            {
                lis_arr[i] = lis_arr[j]+1;
            }
        }
        cout<<"For elements "<<arr[i]<<" Lis(array) is : ";
        for(int k=0; k<n; k++)
        {
            cout<<lis_arr[k]<< " ";
        }
        cout<<endl;
    }
    int maxx = 0,index = 0;

    for(int k=0; k<n; k++)
    {
        if(maxx<lis_arr[k])
        {
            maxx = lis_arr[k];
            index = k;
        }
    }
    //cout<<maxx<<" "<<index<<endl;
    int lis = maxx;
    int last_ind =0;
    vector<int>v;
    for(int i=index; i>=0; i--)
    {
        if(lis_arr[i]==maxx)
        {
            if(maxx==1)
            {
                for(int k=0;k<=i;k++)
                {
                    if((arr[k]+arr[last_ind])%2!=0 && arr[k]<arr[last_ind])
                    {
                        v.push_back(arr[k]);
                        maxx--;
                        break;
                    }
                }
            }
            else{
                v.push_back(arr[i]);
                maxx--;
                last_ind = i;
            }
        }
    }
    for(int i=v.size()-1; i>=0; i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return lis;
}
int Lis_Even_Sequence(int arr[],int n)
{
    int lis_arr[n+1];
    for(int k=0; k<n; k++)
    {
        lis_arr[k]=1;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j] && lis_arr[j]+1>lis_arr[i] && arr[i]%2==0)
            {
                lis_arr[i] = lis_arr[j]+1;
            }
        }
        cout<<"For elements "<<arr[i]<<" Lis(array) is : ";
        for(int k=0; k<n; k++)
        {
            cout<<lis_arr[k]<< " ";
        }
        cout<<endl;
    }
    int maxx = 0,index = 0;

    for(int k=0; k<n; k++)
    {
        if(maxx<lis_arr[k])
        {
            maxx = lis_arr[k];
            index = k;
        }
    }
    int lis = maxx;
    int last_ind = 0;
    vector<int>v;
    for(int i=index; i>=0; i--)
    {
        if(lis_arr[i]==maxx)
        {
            if(maxx==1)
            {
                if(arr[i]%2==0 && arr[i]<arr[last_ind])
                {
                    v.push_back(arr[i]);
                    maxx--;
                    break;
                }
            }else{
                v.push_back(arr[i]);
                maxx--;
                last_ind = i;
            }
        }
    }
    for(int i=v.size()-1; i>=0; i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return lis;
}
int Lis_Odd_Sequence(int arr[],int n)
{
    int lis_arr[n+1];
    for(int k=0; k<n; k++)
    {
        lis_arr[k]=1;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j] && lis_arr[j]+1>lis_arr[i] && arr[i]%2!=0)
            {
                lis_arr[i] = lis_arr[j]+1;
            }
        }
        cout<<"For elements "<<arr[i]<<" Lis(array) is : ";
        for(int k=0; k<n; k++)
        {
            cout<<lis_arr[k]<< " ";
        }
        cout<<endl;
    }
    int maxx = 0,index = 0;

    for(int k=0; k<n; k++)
    {
        if(maxx<lis_arr[k])
        {
            maxx = lis_arr[k];
            index = k;
        }
    }
    int lis = maxx;
    vector<int>v;
    int last_ind = 0;
    for(int i=index; i>=0; i--)
    {
        if(lis_arr[i]==maxx)
        {
            if(maxx==1)
            {
                if(arr[i]%2!=0 && arr[i]<arr[last_ind])
                {
                    v.push_back(arr[i]);
                    maxx--;
                }
            }else{
                v.push_back(arr[i]);
                maxx--;
                last_ind = i;
            }
        }
    }
    for(int i=v.size()-1; i>=0; i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return lis;
}
int Lis_normal(int arr[],int n)
{
    int lis_arr[n+1];
    for(int k=0; k<n; k++)
    {
        lis_arr[k]=1;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j] && lis_arr[j]+1>lis_arr[i])
            {
                lis_arr[i]=lis_arr[j]+1;
            }
        }
        cout<<"For elements "<<arr[i]<<" Lis(array) is : ";
        for(int k=0; k<n; k++)
        {
            cout<<lis_arr[k]<< " ";
        }
        cout<<endl;
    }
    int maxx = 0,index=0;
    for(int k=0; k<n; k++)
    {
        if(maxx<lis_arr[k])
        {
            maxx = lis_arr[k];
            index = k;
        }
    }
    int lis = maxx;
    vector<int>v;
    for(int i=index; i>=0; i--)
    {
        if(lis_arr[i]==maxx)
        {
            v.push_back(arr[i]);
            maxx--;
        }
    }
    for(int k=v.size()-1; k>=0; k--)
    {
        cout<<v[k]<< " ";
    }
    cout<<endl;
    return lis;
    //cout<<maxx<<" "<<index<<" "<<arr[index];
    //return *max_element(lis_arr,lis_arr+n);
}
int main()
{
    //int arr[] = {1, 12, 2, 22, 5, 30, 31, 14, 17, 11};
    //int arr[] = {5, 6, 9, 4, 7, 8};
    //int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int arr[] = {3, 3, 10, 11, 4, 5, 6, 7, 8, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"LIS is : "<<Lis_normal(arr,n)<<endl;
    cout<<"Lis Odd Sequence is : "<<Lis_Odd_Sequence(arr,n)<<endl;
    cout<<"Lis Even Sequence is : "<<Lis_Even_Sequence(arr,n)<<endl;
    cout<<"Lis ALternative odd/even Sequence is : "<<Lis_ALternative_odd_even_Sequence(arr,n)<<endl;
    cout<<"LIs consecutive subsequence is : "<<Lis_consecutive_subsequence(arr,n)<<endl;
}



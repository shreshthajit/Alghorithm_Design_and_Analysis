https://codeforces.com/contest/1673/problem/C

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void setIO()
{
    fast;
}
int n=2005;
vi dist(n);
vvi edges;
void query(int node)
{
    cout<<"? "<<node<<endl;
    for(int i=1; i<=n; i++)
        cin>>dist[i];
}
void addEdge(int u,int v)
{
    edges.push_back({u,v});
}

bool isPrime(int num)
{
    bool flag=true;
    for(int i = 2; i <= num / 2; i++)
    {
        if(num % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

vector<int>v;
int sum=0;
int num;
string st;

int  rec(int i,int j)
{
    if(j-i==1 or i==j)
        return true;
    else
    {
        if(st[i]==st[j])
        {
            return (rec(i+1,j-1));
        }
        else
            return false;
    }
}
int N;
bool IsSafe(int board[100][100],int row,int col)
{
    for(int i=row-1,j=col; i>=0; i--)
    {
        if(board[i][j]==1)
            return false;
    }
    for(int i=row-1,j=col-1; i>=0 and j>=0; i--,j--)
    {
        if(board[i][j]==1)
            return false;
    }
    for(int i=row-1,j=col+1; i>=0 and j<=n-1; i--,j++)
    {
        if(board[i][j]==1)
            return false;
    }
    return true;
}
void solve(int board[100][100],string qsf,int row)
{
    if(row==N)
    {
        cout<<qsf<<endl;
        return;
    }
    for(int col=0; col<N; col++)
    {
        if( IsSafe(board,row,col))
        {
            board[row][col]=1;
            solve(board,qsf+to_string(row)+"-"+to_string(col)+" ,  ",row+1);
            board[row][col]=0;
        }
    }
}
bool isValid(string s)
{
    stack<char>st;
    int i=0;
    st.push(s[i]);
    i++;
    while(!st.empty() and i<s.length())
    {
        char c=st.top();
        if(s[i]==')' and c=='(')
        {
            st.pop();
        }
        else if(s[i]=='}' and c=='{')
        {
            st.pop();
        }

        else if(s[i]==']' and c=='[')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty())
    {
        char c=st.top();
        st.pop();
        cout<<c<<" ";
    }

    if(st.size()>0)
        return false;
    else
        return true;
}

long long moduloMultiplication(long long a,
                               long long b,
                               long long newMod)
{
    long long res = 0; // Initialize result

    // Update a if it is more than
    // or equal to mod
    a %= newMod;

    while (b)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % newMod;

        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % newMod;

        b >>= 1; // b = b / 2
    }
    return res;
}

bool comp(pair<int,int>&p1,pair<int,int>&p2)
{
    return p1.second<p2.second;
}


vector<int>palins;

int createPalindrome(int input, int b, bool isOdd)
{
    int n = input;
    int palin = input;

    if (isOdd)
        n /= b;

    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}

void generate_palindromes(int n)
{
    int number;

    for (int j = 0; j < 2; j++)
    {
        int i = 1;
        while ((number = createPalindrome(i, 10, j % 2)) < n)
        {
            palins.pb(number);
            i++;
        }
    }
    sort(palins.begin(),palins.end());
}

int dp[500001];

void get_ways()
{

    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0; i<palins.size(); i++)
    {
        for(int j=palins[i]; j<=5e4+1; j++)
        {
            dp[j]+=dp[j-palins[i]];

            dp[j]%=mod;
        }

    }
}

 

int main()
{
    generate_palindromes(5e4+1);
    get_ways();
    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }




}


/*













*/

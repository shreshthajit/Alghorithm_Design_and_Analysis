#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 5e5 + 20;
vector<int> adj[maxn];
int st[maxn] , ft[maxn] , now = -1 , is[maxn];



void dfs(int v , int p = -1)
{
	st[v] = ++now;
	cout<<"now= "<<now<<endl;

	for(auto u : adj[v]){
	cout<<"u= "<<u<<" "<<"v= "<<v<<endl;
		if(u != p){

			dfs(u , v);
			}
			}

	ft[v] = now + 1;
}





int mn[maxn * 4] , t[maxn * 4] , Add[maxn * 4] , n;
void build(int s = 0 , int e = n , int v = 1)
{
	t[v] = e - s;
	if(e - s < 2)
		return;

	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
}
void add(int l , int r , int val , int s = 0 , int e = n , int v = 1)
{
	if(l <= s && e <= r)
	{
		mn[v] += val;
		Add[v] += val;
		return;
	}
	if(r <= s || e <= l)
		return;
	int m = (s + e) / 2;
	add(l , r , val , s , m , 2 * v);
	add(l , r , val , m , e , 2 * v + 1);
	mn[v] = min(mn[2 * v] , mn[2 * v + 1]);
	t[v] = 0;
	if(mn[v] == mn[2 * v])
		t[v] += t[2 * v];
	if(mn[v] == mn[2 * v + 1])
		t[v] += t[2 * v + 1];
	mn[v] += Add[v];
}
pair<int , int> get(int l , int r , int s = 0 , int e = n , int v = 1)
{
	if(l <= s && e <= r)
		return make_pair(mn[v] , t[v]);
	if(r <= s || e <= l)
		return make_pair(1e9 , 0);

	int m = (s + e) / 2;
	auto x = get(l , r , s , m , 2 * v);
	auto y = get(l , r , m , e , 2 * v + 1);
	pair<int , int> ans = {1e9 , 0};
	ans.first = min(x.first , y.first);
	if(ans.first == x.first)
		ans.second += x.second;
	if(ans.first == y.first)
		ans.second += y.second;
	ans.first += Add[v];
	return ans;
}
int main()
{
	int q;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		a-- , b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0);
	build();

	/*
	while(q--)
	{
		int type , v;
		cin >> type >> v;
		v--;
		if(type == 1)
		{
			add(st[v] , ft[v] , is[v]? -1 : 1);
			is[v] ^= 1;
		}
		else
		{
			if(is[v])
				printf("0\n");
			else
				printf("%d\n", get(st[v] , ft[v]).second);
		}
	}
	*/
}

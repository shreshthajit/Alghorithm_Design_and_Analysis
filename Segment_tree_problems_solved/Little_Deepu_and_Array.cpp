#include<iostream>
#include<bits/stdc++.h>

using namespace std;
 //
#include<string.h>
#include<math.h>

#define MAX 100005
#define inf 0x7fffffff


int N;
int arr[MAX];
int tree[4*MAX];
int lazy[4*MAX];

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b)
{
  	if(a > b) return;

  	if(a == b)
  	{
    		tree[node] = arr[a];
		return;
	}

	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, 1+(a+b)/2, b);

	tree[node] = min(tree[node*2], tree[node*2+1]);
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int x, int value) {

	 if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    	lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   	lazy[node] = 0; // Reset it
  	}


	if(tree[node] > x) { // Segment is fully within range
  	tree[node] += value;
		if(a != b) { // Not leaf node
				lazy[node*2] += value;
				lazy[node*2+1] += value;
		}
	  return;
  }

  if(a == b) return;
	update_tree(node*2, a, (a+b)/2, i, j,x, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j,x, value); // Updating right child

	tree[node] = min(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return inf;

	if(lazy[node] != 0) {
		tree[node] += lazy[node];

		if(a != b) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}

		lazy[node] = 0;
	}

	if(a >= i && b <= j)
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j);
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
	int res = min(q1, q2);

	return res;
}

int main()
{
	cin >> N;
	assert(N < 1000001);


	vector<pair<int,int> > ds;

	for(int i=0;i<N;i++)
	{
		int a;
		cin >> a;
		assert(a < 1000000000);
		ds.push_back(make_pair(a,i+1));
	}







	sort(ds.begin(),ds.end());
	for(int i=0;i<N;i++){
		arr[i] = ds[i].first;
	}
	build_tree(1, 0, N-1);
	memset(lazy, 0, sizeof lazy);
	int Q;
	cin >> Q;
	assert(Q <= 20000);
	while(Q--){
		int x;
		cin >> x;
		assert(x <= 1000000000);
		update_tree(1, 0, N-1 , 0 , N-1, x, -1);
	}
	for(int i=0;i<N;i++){
		ds[i].first = query_tree(1, 0, N-1, i, i);
		swap(ds[i].first, ds[i].second);
	}
	sort(ds.begin(),ds.end());
	for(int i=0;i<N;i++){
		cout << ds[i].second << " ";
	}
	cout << endl;
}

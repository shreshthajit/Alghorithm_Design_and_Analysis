#include <iostream>
using namespace std;
int tree[4000000];
void build(int node, int st, int en) {
	if (st == en) {
		tree[node] = 1;
		return;
	}
	int mid = (st+en)/2;
	build(2*node, st, mid);
	build(2*node+1, mid+1, en);
	tree[node] = tree[2*node] + tree[2*node+1];
}
void update(int node, int st, int en, int index) {
	if (st == index && en == index) {
		tree[node] = 0;
		return;
	}
	int mid = (st+en)/2;
	if(index >= st && index <= mid) {
		update(2*node, st, mid, index);
	} else {
		update(2*node+1, mid+1, en, index);
	}
	tree[node] = tree[2*node] + tree[2*node+1];
}
//every time we will go to right if the total sum is greater than the left node otherwise we will chose rightnode....
int query(int node, int st, int en, int k, int n) {
	if (st < 1 || en > n || tree[node] < k) {
		return -1;
	}
	if (st == en && k == 1) {
		return st;
	}
	int val = tree[node];
	int mid = (st+en)/2;
	int leftNode = tree[2*node];
	int rightNode = tree[2*node+1];
	if (k >leftNode) {
		return query(2*node+1, mid+1, en, k-leftNode, n);
	} else {
		return query(2*node, st, mid, k, n);
	}
}
int main() {
	int N, K, Q, type, I;
	cin >> N;
	build(1, 1, N);
	cin >> Q;
	while(Q--) {
		cin >> type;
		if (type) {
			cin >> K;
			cout << query(1, 1, N, K, N) << endl;
		} else {
			cin >> I;
			update(1, 1, N, I);
		}
	}
	return 0;
}

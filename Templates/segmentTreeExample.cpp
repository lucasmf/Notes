#include <bits/stdc++.h>

using namespace std;

//nao testado!

#define MAXN 501000
#define LEFT(p) (2*p+1)
#define RIGHT(p) (2*p+2)
#define MID(a, b) ((a+b)/2)

struct node {
	int sum;
	node() {
		sum = 0;
	}
	node(int v) {
		sum = v;
	}
	
};
	
node st[4*MAXN];
int arr[MAXN];

node join(node left, node right) {
	int sum = left.sum + right.sum;
	return node(sum);
}

void build(int p, int beg, int end) {
	if(beg > end) return;
	if(beg == end) {
		st[p] = node(arr[beg]);
		return;
	}
	build(LEFT(p), beg, MID(beg, end));
	build(RIGHT(p), MID(beg, end)+1, end);
	st[p] = join(st[LEFT(p)], st[RIGHT(p)]);
	
}

void update(int p, int idx, int beg, int end, char c) {
	if(beg > end || beg > idx || end < idx) return;
	if(beg == end) {
		st[p] = node(c);
		return;
	}
	update(LEFT(p), idx, beg, MID(beg, end), c);
	update(RIGHT(p), idx, MID(beg, end)+1, end, c);
	st[p] = join(st[LEFT(p)], st[RIGHT(p)]);
}


node read(int p, int i, int j, int beg, int end)  {
	if(beg > end || beg > j || end < i) return node();
	if(beg >= i && end <= j) return st[p];
	node left = read(LEFT(p), i, j, beg, MID(beg, end));
	node right = read(RIGHT(p), i, j, MID(beg, end) + 1, end);
	return join(left, right);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	build(0, 0, n-1);
	return 0;
}



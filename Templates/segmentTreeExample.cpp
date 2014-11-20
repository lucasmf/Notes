#include <bits/stdc++.h>

using namespace std;

//nao testado!

#define MAXN 30010
#define LEFT(p) (2*p)
#define RIGHT(p) (2*p+1)
#define MID(a, b) ((a+b)/2)

struct node {
	int sum;
	int minimum;
	node() {}
	node(char c) {
		sum = (c=='(' ? 1 : -1);
		minimum = min(0, sum);
	}
	node(int a, int b) {
		sum = a;
		minimum = b;
	}
};
	
node st[4*MAXN];
char word[MAXN];

node join(node left, node right) {
	int sum = left.sum + right.sum;
	int minimum = min(left.minimum, right.minimum+left.sum);
	return node(sum, minimum);
}

void build(int p, int beg, int end) {
	if(beg > end) return;
	if(beg == end) {
		st[p] = node(word[beg]);
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
	for(int test = 1; test<=10; test++) {
		printf("Test %d:\n", test);
		int n;
		scanf("%d", &n);
		scanf(" %s", word);
		build(1, 0, n-1);
		//printf("%d", read(1, 0, n-1));
		int m;
		scanf("%d", &m);
		for(int i = 0; i<m; i++) {
			int q;
			scanf("%d", &q);
			if(q == 0) {
				printf("%s\n", read(1, 0, n-1, 0, n-1).minimum == 0?"YES":"NO"); 
			}
			else {
				if(word[q-1] == ')') word[q-1] = '(';
				else  word[q-1] = ')';
				update(1, q-1, 0, n-1, word[q-1]);
			}
		}
	}
	return 0;
}



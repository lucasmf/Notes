#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int sa[MAXN];
int invsa[MAXN];
string str;
int x;

bool comp(int a, int b) {
	if(invsa[a] == invsa[b])
		return invsa[a+x] < invsa[b+x];
	else return invsa[a] < invsa[b];
}

void qsort(int a, int b) {
	if(a == b) return;
	int pivot = sa[a+(rand()%(b-a))];
	int c = a;
	int d = b;
	for(int i = c; i<b; i++) {
		if(comp(sa[i], pivot)) swap(sa[c++], sa[i]);
	}
	for(int i = d-1; i>=a; i--) {
		if(comp(pivot, sa[i])) swap(sa[i], sa[--d]);
	}
	qsort(a, c);
	for(int i = c; i<d; i++) {
		invsa[sa[i]] = d-1;
	}
	qsort(d, b);
}
void solve() {
	for(int i = 0; i<(int)str.size(); i++) {
		sa[i] = i;
		invsa[i] = str[i];
	}
	invsa[str.size()] = -1;
	x = 0;
	qsort(0, str.size());
	
	for(x = 1; x<(int)str.size(); x*=2) {
		for(int i = 0, j; i<(int)str.size(); i = j) {
			qsort(i, j = invsa[sa[i]]+1);
		}
	}
}

int main() {
	cin >> str;
	solve();
	for(int i = 0; i<(int)str.size(); i++) {
		printf("%d\n", sa[i]);
	}
	return 0;
}


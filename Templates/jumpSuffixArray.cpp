#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int sa[MAXN];
int invsa[MAXN];
string str;
int x, size;

bool comp(int a, int b) {
	return invsa[a+x] < invsa[b+x];
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
	if (d-c == 1) sa[c] = -1;
	qsort(d, b);
}
void solve() {
	for(int i = 0; i<size	; i++) {
		sa[i] = i;
		invsa[i] = str[i];
	}
	invsa[str.size()] = -1;
	x = 0;
	qsort(0, str.size());
	
	for(x = 1; x<size; x*=2) {
		for(int i = 0, j; i<size; i = j) {
			if (sa[i] < 0) {
				j = i;
				while (sa[j] < 0)
					j += -(sa[j]);
				sa[i] = -(j-i);
			} else {
				qsort(i, j = invsa[sa[i]]+1);
			}
		}
	}
	for (int i = 0; i < size; i++) sa[invsa[i]] = i;
}

int main() {
	char str_aux[MAXN];
	scanf(" %s", str_aux);
	str = (string)str_aux;
	size = str.size();
	solve();
	for(int i = 0; i<size; i++) {
		printf("%d\n", sa[i]);
	}
	return 0;
}


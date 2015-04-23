#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000000100LL
#define MAXN 1000010

vector<long long> v;
int next[2*MAXN+10];

int solve(int start, int siz) {
	int ret = 0;
	for(int end = start; end-start < siz; ret++, end = next[end]);
	return ret;
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	v.push_back(0);
	for(int i = 0; i<n; i++) {
		int aux;
		scanf("%d", &aux);
		v.push_back(aux);
	}
	for(int i = 0; i<n; i++) {
		v.push_back(v[i]);
	}
	for(int i = 1; i<(int)v.size(); i++) {
		v[i] += v[i-1];
	}
	v.push_back(INF);
	while(q--) {
		long long b;
		int aux = 0;
		scanf("%lld", &b);
		for(int i = 1; i<(int)v.size(); i++) {
			while(v[aux]-v[i-1] <= b) aux++;
			next[i] = aux;
		}
		int startPoint = 0, endPoint = 0;
		int minSize = 2*MAXN;
		for(int i = 1; i<=n; i++) {
			if(next[i] - i < minSize) {
				startPoint = i;
				endPoint = next[i];
				minSize = next[i] - i;
			}
		}
		printf("->%d %d\n", startPoint, endPoint);
		int ret = 2*MAXN;
		for(int i = startPoint; i<endPoint; i++) {
			ret = min(ret, solve(i, n));
		}
		printf("%d\n", ret);	
	}
	return 0;
}
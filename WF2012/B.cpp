#include <bits/stdc++.h>

using namespace std;

#define MAXN 22

int v[MAXN], r[MAXN];
double pi;

double bs(double beg, double end, double expected) {
	double mid;
	for(int cnt = 0; cnt<100; cnt++) {
		mid = (beg+end)/2;
		double actual = 0.0;
		for(int i = 0; i<MAXN; i++) {
			actual += v[i]*mid;
		}
		actual *= pi;
		if(actual > expected) end = mid;
		else beg = mid;
	}
	return mid;
}

int main() {
	
	pi = acos(-1);
	
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++) {
		scanf("%d", &v[i]);
	}
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			r[i+j]+=v[i]*v[j];
		}
	}
	return 0;
}

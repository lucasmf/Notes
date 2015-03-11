#include <bits/stdc++.h>

using namespace std;
//AC

vector<int> v;
int n, k;

bool check(int x) {
	long long q = 0;
	int idx = 0;
	while(idx < v.size()) {
		if(idx == v.size()-1) {
			q--;
			idx++;
		}
		else if(v[idx+1]-v[idx] <= x) {
			q += 2*(k-1);
			idx += 2;
		}
		else {
			q--;
			idx++;
		}

		if(q < 0) return false;
	}
	return true;
}

int solve() {
	int beg = 0; 
	int end = 1000000000;
	int mid;
	int ret;
	while(beg <= end) {
		mid = (beg+end)/2;
		if(check(mid)) {
			ret = mid;
			end = mid-1;
		}
		else {
			beg = mid+1;
		}
	}
	return ret;
}

int main() {
	while(scanf("%d %d", &n, &k) != EOF) {
		v.clear();
		for(int i = 0; i<2*n*k; i++) {
			int x;
			scanf("%d", &x);
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		printf("%d\n", solve());
	}
	return 0;
}
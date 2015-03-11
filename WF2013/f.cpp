#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

vector<lint> v;
lint n, m;

bool check(lint x) {
	lint q = 0;
	lint i = 0;
	while(i < v.size()) {
		if(i == v.size()-1) {
			q--;
			i++;
		}
		else {
			if(v[i+1] - v[i] <= x) {
				q += 2*(m-1);
				i += 2;
			}
			else {
				q--;
				i++;
			}
		}
		if(q < 0) return false;
	}
	return true;
}

lint bs() {
	lint beg = 0, end = 1000000010;
	lint mid;
	lint ret;
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
	while(scanf("%lld %lld", &n, &m) != EOF) {
		v.clear();
		for(int i = 0; i<2*n*m; i++) {
			lint x;
			scanf("%lld", &x);
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		printf("%lld\n", bs());
	}
	return 0;
}
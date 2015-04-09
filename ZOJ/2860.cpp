#include <bits/stdc++.h>

using namespace std;

vector<int> v;

#define MAXM 1010

long long int dp[MAXM][MAXM];

int pos[MAXM][MAXM];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	v.push_back(0);
	for(int i = 0; i<m; i++) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	v.push_back(n);
	for(int s = 2; s<v.size(); s++) {
		for(int i = 0; i+s<v.size(); i++) {
			int j = i+s;
			if(s == 2) {
				dp[i][j] = v[j]-v[i];
				pos[i][j] = i+1;
			}
			else {
				dp[i][j] = 1000000000000000;
				for(int k = pos[i][j-1]; k<=pos[i+1][j]; k++) {
					if(dp[i][j] > v[j]-v[i]+dp[i][k]+dp[k][j]) {
						dp[i][j] = min(dp[i][j], v[j]-v[i]+dp[i][k]+dp[k][j]);
						pos[i][j] = k;
					}
				}
			}
		}
	}
	printf("%lld\n", dp[0][m+1]);
	return 0;
}
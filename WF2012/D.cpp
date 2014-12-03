#include <bits/stdc++.h>

using namespace std;

#define MAXN 110;

struct p {
	int q;
	string beg;
	string end;
	p() {}
};

p dp[MAXN];

int main() {
	int n;
	string pat;
	scanf("%d", &n);
	cin >> pat;
	dp[0].q = KMP();
	dp[0].beg = "0";
	dp[0].end = "1";
	dp[1].q = KMP();
	dp[1].beg = "1";
	dp[1].end = "1";
	for(int i = 2; i<

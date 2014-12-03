#include <bits/stdc++.h>
#include <cstring>
#include <time.h>

using namespace std;

//AC!

#define MAX_N 100010
#define MAXN 110

struct p {
	long long int q;
	string beg;
	string end;
	string palavra;
	p() {}
};

p dp[MAXN];

string T, P;
int b[MAX_N]; // b = back table, n = length of T, m = length of P

void kmpPreprocess() { // call this before calling kmpSearch()
  int i = 0, j = -1; b[0] = -1; // starting values
  while (i < (int)P.size()) { // pre-process the pattern string P
    while (j >= 0 && P[i] != P[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
} }           // in the example of P = "SEVENTY SEVEN" above

int kmpSearch() { // this is similar as kmpPreprocess(), but on string T
  
  int ret = 0;
  int i = 0, j = 0; // starting values
  while (i < (int)T.size()) { // search through string T
    while (j >= 0 && T[i] != P[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    if (j == (int)P.size()) { // a match found when j == m
	  ret++;
      //printf("P is found at index %d in T\n", i - j);
      j = b[j]; // prepare j for the next possible match
	}
  }
  return ret;
}

int main() {
	int n;
	int test = 1;
	while(scanf("%d", &n) != EOF) {
		bool flag = false;
		cin >> P;	
		kmpPreprocess();
		T = "0";
		dp[0].q = kmpSearch();
		dp[0].palavra = "0";
		T = "1";
		dp[1].q = kmpSearch();
		dp[1].palavra = "1";
		for(int i = 2; i<=n; i++) {
			if(dp[i-1].palavra.size() >= P.size() && dp[i-2].palavra.size() >= P.size()) flag = true; 
			if(!flag) {
				dp[i].palavra = dp[i-1].palavra + dp[i-2].palavra;
				T = dp[i].palavra;
				if(dp[i].palavra.size() >= P.size()) {
					dp[i].beg = dp[i].palavra.substr(0, P.size()-1);
					dp[i].end = dp[i].palavra.substr(dp[i].palavra.size()-(P.size()-1), P.size());
				}
				dp[i].q = kmpSearch();
			}
			else {			
				T = dp[i-1].end + dp[i-2].beg;
				dp[i].q = dp[i-1].q + dp[i-2].q + kmpSearch();
				dp[i].beg = dp[i-1].beg;
				dp[i].end = dp[i-2].end;
			}
			//printf("%d -> %d\n", i, dp[i].q);
		}
		printf("Case %d: %lld\n", test, dp[n].q);
		test++;
	}
	return 0;
}

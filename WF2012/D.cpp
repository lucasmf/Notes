#include <bits/stdc++.h>
#include <cstring>
#include <time.h>
using namespace std;

#define MAX_N 100010
#define MAXN 110

struct p {
	int q;
	string beg;
	string end;
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
      printf("P is found at index %d in T\n", i - j);
      j = b[j]; // prepare j for the next possible match
	}
  }
  return ret;
}

int main() {
	int n;
	string P;
	scanf("%d", &n);
	cin >> P;
	kmpPreprocess();
	T = "0";
	dp[0].q = kmpSearch();
	dp[0].beg = "0";
	dp[0].end = "1";
	T = "1";
	dp[1].q = kmpSearch();
	dp[1].beg = "1";
	dp[1].end = "1";
	printf("%d %d\n", dp[0].q, dp[1].q);
	return 0;
}

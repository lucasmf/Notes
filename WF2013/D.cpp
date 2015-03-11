#include <bits/stdc++.h>

using namespace std;

//AC!!!!

typedef long long lint;
#define MAXN 64
#define MAXT 20

bool isPrimos[MAXN];

map<lint, lint> mm;

vector<lint> primes;
vector<lint> bestNumbers;
bool isPrime[MAXN];

void crivo() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[1] = false;
	for(int i = 2; i<MAXN; i++) {
		if(isPrime[i]) {
			primes.push_back(i);
			for(int j = 2*i; j<MAXN; j+=i) {
				isPrime[j] = false;
			}
		}
	}
}

void rec(int idx, lint v, int last) {
	if(idx == primes.size()) return;
	for(int i = 0; i<last; i++) {
		lint aux = v;
		for(int lol = 0; lol<primes[idx]-1; lol++) {
			v += aux;
			if(v < 0) return;
		}
		bestNumbers.push_back(v);
		rec(idx+1, v, i+1);
	}
}

lint getQ(lint number) {
	lint naux = number;
	vector<int> quantities;
	quantities.clear();
	int q[MAXT];
	memset(q, 0, sizeof(q));
	int total = 0;
	for(int i = 0; number != 1; i++) {
		
		int add = 0;
		while(number % primes[i] == 0) {
			add++;
			number/=primes[i];
		}
		total += add;
		if(add != 0)quantities.push_back(add);
	}
	
	for(int i = 2; i<=total; i++) {
		lint aux = i;
		for(int j = 0; aux != 1; j++) {
			while(aux%primes[j] == 0) {
				q[j]++;
				aux/=primes[j];
			}
		}
	}
	
	for(int k = 0; k<quantities.size(); k++) {
		for(int i = 2; i<=quantities[k]; i++) {
			lint aux = i;
			for(int j = 0; aux != 1; j++) {
				while(aux%primes[j] == 0) {
					q[j]--;
					aux/=primes[j];
				}
			}
		}
	}
	
	lint ret = 1;
	for(int i = 0; i<MAXT; i++) {
		for(int lol2 = 0; lol2<q[i]; lol2++) {
			lint aux = ret;
			for(int lol = 0; lol<primes[i]-1; lol++) {
				ret += aux;
				if(ret < 0) return 0;
			}	
		}
	}
	
	return ret;
}

int main() {
	crivo();
	long long mul = 1;

	rec(0, 1, 64);
	
	for(int i = 0; i<(int)bestNumbers.size(); i++) {
		lint x = getQ(bestNumbers[i]);

		mm[x] = mm[x] == 0?bestNumbers[i]:min(mm[x], bestNumbers[i]);
	}
	mm[1] = 2;
	
	lint x;
	while(scanf("%lld", &x) != EOF) {
		printf("%lld %lld\n", x, mm[x]);
	}
	return 0;
}
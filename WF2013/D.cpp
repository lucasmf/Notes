#include <bits/stdc++.h>

using namespace std;

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
		v *= primes[idx];
		if(v < 0) return;
		bestNumbers.push_back(v);
		rec(idx+1, v, i+1);
	}
}

lint getQ(lint number) {
	vector<int> quantities;
	quantities.clear();
	int q[MAXT];
	memset(q, 0, sizeof(q));
	int total = 0;
	/*for(int i = 0; number != 1; i++) {
		printf("%lld\n", number);
		int add = 0;
		while(number % primes[i] == 0) {
			add++;
			number/=primes[i];
		}
		total += add;
		if(add != 0)quantities.push_back(add);
	}
	for(int i = 2; i<=total; i++) {
		int aux = i;
		for(int j = 0; aux != 1; j++) {
			while(aux%primes[j] == 0) q[j]++;
		}
	}
	for(int k = 0; k<quantities.size(); k++) {
		for(int i = 2; i<=quantities[k]; i++) {
			int aux = i;
			for(int j = 0; aux != 1; j++) {
				while(aux%primes[j] == 0) q[j]--;
			}
		}
	}*/
	lint ret = 1;
	for(int i = 0; i<MAXN; i++) {
		while(q[i]) {
			ret *= q[i];
			if(ret < 0) return 0;
			q[i]--;
		}
	}
	return ret;
}

int main() {
	for(lint i = 1; i*i<65401157644647821LL; i++) {
		if(65401157644647821LL % i == 0) printf("%lld\n", i);
	}
	crivo();
	long long mul = 1;
	for(int i = 0; i<primes.size(); i++) {
		mul = mul*primes[i];
		printf("-> %lld %lld\n", primes[i], mul);
	}

	rec(0, 1, 64);
	printf("%d\n", (int)bestNumbers.size());
	for(int i = 0; i<(int)bestNumbers.size(); i++) {
		lint x = getQ(bestNumbers[i]);
		mm[x] = min(mm[x], bestNumbers[i]);
	}
	mm[2] = 1;
	for(int i = 0; i<10; i++) {
		lint x;
		scanf("%lld", &x);
		printf("%lld\n", mm[x]);
	}
	return 0;
}
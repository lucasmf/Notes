#include <bits/stdc++.h>

using namespace std;

struct food {
	int P, C, F;
	food(int _P, int _C, int _F) {
		P = _P;
		C = _C;
		F = _F;
	}
};


map<int, int> expoent;

vector<food> lista;

void pre() {
	for(int i = 0, x = 1; i<21; i++, x*=2) {
		expoent[x] = i;
	}
}

int main() {

	freopen("new_years_resolution.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	pre();

	int test = 1;

	int t;
	scanf("%d", &t);
	while(t--) {
		int Gp, Gc, Gf;
		bool flag = false;
		lista.clear();
		scanf("%d %d %d", &Gp, &Gc, &Gf);
		int n;
		scanf("%d", &n);
		for(int i = 0; i<n; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			lista.push_back(food(a, b, c));
		}
		for(int i = 0; i<(1<<n); i++) {
			int aux = i;
			int P = 0;
			int C = 0;
			int F = 0;
			while(aux) {
				int sub = aux&(-aux);
				int idx = expoent[sub];
				aux -= sub;
				P += lista[idx].P;
				C += lista[idx].C;
				F += lista[idx].F;
			}
			if(P == Gp && C == Gc && F == Gf) {
				flag = true;
				break;
			}
		}
		printf("Case #%d: %s\n", test, flag?"yes":"no");
		test++;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

//AC!

#define MAXN 23

double v[MAXN], r[MAXN];
double pi;
double dif, maximum;

double calc(double x) {
	double ret = 0.0;
	double mult = x;
	for(int i = 0; i<MAXN; i++, mult*=x) {
		ret += r[i]*mult;
	}
	return ret*pi;
}

double bs(double beg, double end, double expected) {
	double mid;
	for(int cnt = 0; cnt<100; cnt++) {
		mid = (beg+end)/2;
		double atual = 0.0;
		atual = calc(mid) - dif;
		if(atual > expected) end = mid;
		else beg = mid;
	}
	return mid;
}

int main() {
	
	pi = acos(-1);
	int n;
	double xLow, xHigh, inc;
	int test = 1;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i<=n; i++) {
			scanf("%lf", &v[i]);
		}
		for(int i = 0; i<MAXN; i++) r[i] = 0;
		scanf("%lf %lf %lf", &xLow, &xHigh, &inc);
		for(int i = 0; i<=n; i++) {
			for(int j = 0; j<=n; j++) {
				r[i+j]+=v[i]*v[j];
			}
		}
		for(int i = 1; i<=2*n; i++) {
			r[i]/=(i+1);
		}
		dif = calc(xLow);
		maximum = calc(xHigh) - dif;
		printf("Case %d: %.2lf\n", test, maximum);
		if(inc > maximum) {
			printf("insufficient volume\n");
		}
		else {
			double expected = inc;
			for(int i = 0; i<8; i++, expected += inc) {
				if(expected > maximum) break;
				double mark = bs(xLow, xHigh, expected);
				if(i == 0) printf("%.2lf", mark-xLow);
				else printf(" %.2lf", mark-xLow);
			}
			printf("\n");
		}
		test++;
	}
	return 0;
}

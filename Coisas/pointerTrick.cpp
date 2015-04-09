#include <bits/stdc++.h>

using namespace std;

int main() {
	int a = 3;
	int *b = &a;
	int **c = &b;
	printf("%d\n", **c);

	double d = -11.75;
	long long* e = (long long*) &d;
	for(int i = 63; i>=0; i--) {
		printf("%lld", (*e>>i)&1);
	}
	cout << endl;

	return 0;
}
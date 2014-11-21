#include <bits/stdc++.h>

using namespace std;

#define pb push_back

struct point {
	int x, y;
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

vector<point> points;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n ;i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		points.pb(point(x, y));
	}
	for(int i = 0; i<n; i++) {
		for(int j = i+1; j<n; j++) {
			for(int k = 0; k<n; k++) {
				
			}
		}
	}
	
	printf("%d\n", r);
	return 0;
}


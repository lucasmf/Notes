#include <bits/stdc++.h>

using namespace std;

#define pb push_back

//AC, de primeira!

struct point {
	int x, y;
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

vector<point> points;

double getDist(point p1, point p2, point p3) {
	double a, b, c;
	double deltaX = p2.x - p1.x;
	double deltaY = p2.y - p1.y;
	if(deltaX == 0) {
		a = 1;
		b = 0;
		c = -p1.x;
	}
	else {
		a = -deltaY*1000/deltaX;
		b = 1*1000;
		c = -(a*p1.x + b*p1.y);
	}
	//printf("a: %.2lf b: %.2lf c: %.2lf\n", a, b, c);
	return (a*p3.x + b*p3.y + c)/sqrt(a*a + b*b);
}


int main() {
	int test = 0;
	while(1) {
		test++;
		int n;
		double left = 0.0;
		double right = 0.0;
		double r = 1000000000;
		points.clear();
		scanf("%d", &n);
		if(n == 0) break;
		for(int i = 0; i<n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			points.pb(point(x, y));
		}
		for(int i = 0; i<n; i++) {
			for(int j = i+1; j<n; j++) {
				left = 0.0;
				right = 0.0;
				for(int k = 0; k<n; k++) {
					if(k != i && k != j) {
						double dist = getDist(points[i], points[j], points[k]);
						left = min(left, dist);
						right = max(right, dist);
					}
				}
				//printf("left:%.2lf right:%.2lf\n", left, right);
				r = min(r, right-left);
				
			}
		}
		printf("Case %d: %.2lf\n", test, r);
	}
	return 0;
}

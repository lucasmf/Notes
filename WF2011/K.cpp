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

double getDist(point p1, point p2, point p3) {
	point vetor1 = point(p2.x - p1.x, p1.y - p2.y);
	point vetor2 = point(p3.x - p1.x, p3.y - p2.y);
	double area = vetor1.x*vetor2.y - vetor1.y*vetor2.y;
	area /= 2;
	return area/sqrt(vetor1.x*vetor1.x + vetor1.y*vetor1.y);
}


int main() {
	int n;
	double left = 0.0;
	double right = 0.0;
	double r = 1000000000;
	scanf("%d", &n);
	for(int i = 0; i<n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		points.pb(point(x, y));
	}
	for(int i = 0; i<n; i++) {
		for(int j = i+1; j<n; j++) {
			for(int k = 0; k<n; k++) {
				left = 0;
				right = 0;
				double dist = getDist(points[i], points[j], points[k]);
				left = min(left, dist);
				right = max(right, dist);
			}
			r = min(r, right-left);
			
		}
	}
	printf("%.2f\n", r);
	return 0;
}

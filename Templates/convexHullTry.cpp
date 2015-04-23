#include <bits/stdc++.h>

using namespace std;

#define INF 2000000000

struct point {
	int x, y;
	point() {
		x = -INF;
		y = -INF;
	}
	point(int x_, int y_) {
		x = x_;
		y = y_;
	}

	bool operator<(const point& other) const {
		if(x != other.x) return x<other.x;
		return y<other.y;
	}
};

vector<point> points;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		points.push_back(point(x, y));
	}
	sort(points.begin(), points.end());
	for(int i = 0; i<(int)points.size(); i++) {
		printf("%d %d\n", points[i].x, points[i].y);
	}
	return 0;
}
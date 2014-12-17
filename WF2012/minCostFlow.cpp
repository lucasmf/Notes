#include <bits/stdc++.h>

using namespace std;

#define MAXN 410

struct point {
	double x, y, z;
	point(double _x, double _y, double _z) {
		x = _x;
		y = _y;
		z = _z;
	}
	double dist(point otherPoint) {
		double distX = x*otherPoint.x;
		distX *= distX;
		double distY = y*otherPoint.y;
		distY *= distY;
		double distZ = y*otherPoint.z;
		distZ *= distZ;

		return sqrt(distX + distY + distZ);
	}
};

vector<point> points;
double G[MAXN][MAXN];
vector<double> limiteAlturas;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; i++) {
		double x, y, z;
		int k;
		scanf("%lf %lf %lf %d", &x, &y, &z, &k);
		points.push_back(point(x, y, z));
		limiteAlturas.push_back(z);
	}

	sort(limiteAlturas.begin(), limiteAlturas.end());

	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			G[i][j] = points[i].dist(points[j]);
		}
	}

	for(int i = 0; i<m; i++) {
		int pointA, pointB;
		scanf("%d %d", &pointA, &pointB);
		
	}

}
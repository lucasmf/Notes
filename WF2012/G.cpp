#include <bits/stdc++.h>

using namespace std;

#define MAXN 410

struct point {
	double x, y, z;
	int k;
	int cumulativeK;
	point(double _x, double _y, double _z, int _k) {
		x = _x;
		y = _y;
		z = _z;
		k = _k;
		cumulativeK = 0;
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

const double INF = 100000000000;
const double EPS = 1e-6;

int n, m;

vector<point> points;
double G[MAXN][MAXN];
vector<pair<double, int> > heightLimits;
int component[MAXN];
int componentK[MAXN]; // Usado para pegar a quantidades de aberturas que um no tem em seu componemte com uma altura menor ou igual a dele

void dfs(int p, int idx) {
	if(component[p] != 0) return;
	component[p] = idx;
	for(int i = 0; i<n; i++) {
		if(fabs(G[p][i]) < EPS) dfs(i, idx);
	}
}

/*TODO:
Ajeitar a marcacao dos components, deve ser feita antes de comecar o dijkstra, ver caso em que mais de um no tem a mesma altura.
*/

int main() {
	freopen("input.txt", "r", stdin);
	double minimumHeight;
	double r = INF;
	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; i++) {
		double x, y, z;
		int k;
		scanf("%lf %lf %lf %d", &x, &y, &z, &k);
		points.push_back(point(x, y, z, k));
		heightLimits.push_back(make_pair(z, i));
	}

	minimumHeight = min(points[0].z, points[n-1].z);

	sort(heightLimits.begin(), heightLimits.end());

	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			G[i][j] = points[i].dist(points[j]);
		}
	}

	for(int i = 0; i<m; i++) {
		int pointA, pointB;
		scanf("%d %d", &pointA, &pointB);
		G[pointA][pointB] == 0;
	}

	int idx = 1;
	for(int i = 0; i<(int)heightLimits.size(); i++) {
		if(component[heightLimits[i].second] == 0) {
			dfs(heightLimits[i].second, idx++);
		}
	}

	for(int i = 0; i<(int)heightLimits.size(); i++) {
		int node = heightLimits[i].second;
		points[node].cumulativeK = componentK[component[node]] + points[node].k;
		componentK[component[node]] += points[node].k;
	}

	for(int i = 0; i<n; i++) {	
		printf(">> %d %d %d %d\n", i, component[i], points[i].k, points[i].cumulativeK);
	}

	/*for(int i = 0; i<n; i++) {
		if(heightLimits[i].first > minimumHeight && fabs(heightLimits[i].first - minimumHeight) < EPS) {
			dijkstra(i, heightLimits[i].first);
			r = min(r, dis[n-1]);
		}
	}

	if(fabs(r-INF) > EPS) 
		printf("%.4lf\n", r);
	else
		printf("impossible\n");
*/
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define MAXN 41
#define INF 1000000000

map<string, int> mm;
int res[MAXN][MAXN], mf, f, s, t;
vector<int> p;

void augment(int v, int minEdge) {
	if(v == s) {
		f = minEdge;
		cout << "AQUII\n" << f << endl;
		return;
	}
	else if(p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
	

}

int solve() {
	cout << "A\n";
	mf = 0;
	while(1) {
		f = 0;
		vector<int> dist(MAXN, INF);
		dist[s] = 0;
		queue<int> q;
		q.push(s);
		p.assign(MAXN, -1);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			if(u == t) break;
			for(int v = 0; v<MAXN; v++) {
				if(res[u][v] > 0 && dist[v] == INF) {
					dist[v] = dist[u]+1;
					q.push(v);
					p[v] = u;
				}	
			}
		}
		augment(t, INF);
		if(f == 0) break;
		mf += f;
	}
	return mf;
}

void pre() {
	for(int i = 0; i<MAXN; i++)
		for(int j = 0; j<MAXN; j++)
			res[i][j] = 0;
	mf = 0;
	s = 0;
	t = MAXN-1;
}

int main() {
	mm["XS"] = 1;
	mm["XS"] = 2;
	mm["M"] = 3;
	mm["L"] = 4;
	mm["XL"] = 5;
	mm["XLL"] = 6;
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		pre();
		scanf("%d %d", &n, &m);
		int qEach = n/6;
		for(int i = 1; i<=6; i++)
			res[s][i] = qEach;
		for(int i = 7; i<7+m; i++)
			res[i][t] = 1;

		for(int i = 0; i<m; i++) {
			string shirt1, shirt2;
			cin >> shirt1 >> shirt2;
			res[mm[shirt1]][7+i] = INF;
			res[mm[shirt2]][7+i] = INF;
		}
		
		for(int i = 0; i<15; i++) {
			for(int j = 0; j<15; j++) {
				printf("%d ", res[i][j]);
			}
			printf("\n");
		}
		printf("%d\n", solve());
		printf("%s\n", solve() == m?"YES":"NO");
	}
	return 0;
}
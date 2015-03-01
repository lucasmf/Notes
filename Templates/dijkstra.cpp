#include <bits/stdc++.h>

using namespace std;

#define MAXN 510000
#define INF 2000000000

//FALTA TESTAR!

struct edge {
	int u, v;
	int w;
	edge(int u_, int v_, int w_) {
		u = u_;
		v = v_;
		w = w_;
	}
	edge() {}
};

int dis[MAXN];
bool vis[MAXN];
vector<edge> edges[MAXN];

void dijkstra(int Vo) {
	
	priority_queue<pair<int, int> > pq;

	for(int i = 0; i<MAXN; i++) {
		dis[i] = INF;
		vis[i] = false;
	}
	dis[Vo] = 0;
	vis[Vo] = true;

	pq.push(make_pair(-dis[Vo], Vo));

	while(true) {
		if(!pq.empty()) {
			pair<int, int> aux = pq.top();
			pq.pop();
			int u = aux.second;
			int disV = -1*aux.first;
			for(int i = 0; i<(int)edges[u].size(); i++) {
				int v = edges[u][i].v;
				int w = edges[u][i].w;
				if(dis[v] > dis[u]+w) {
					dis[v] = dis[u] + w;
					pq.push(make_pair(-dis[v], v));
				}
			}
		}
		else 
			break;
	}
}

int main() {
	
	//freopen("input.txt", "r", stdin);

	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i<m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges[u].push_back(edge(u, v, w));
		edges[v].push_back(edge(v, u, w));
	}

	dijkstra(0);

	for(int i = 0; i<n; i++) {
		printf("dis[%d] -> %d\n", i, dis[i]);
	}

	return 0;
}
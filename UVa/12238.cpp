#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define MAXLOG 15

vector<int> G[MAXN];
int up[MAXN][MAXLOG];
int pot[MAXLOG];
bool vis[MAXN];
int level[MAXN];
long long dist[MAXN];
int cost[MAXN];

void pre() {
	pot[0] = 1;
	for(int i = 1; i<MAXLOG; i++) pot[i] = pot[i-1]*2;
}

void buildLCA(int node, int last, int l, long long c) {
	if(vis[node]) return;
	dist[node] = c + cost[node];
	vis[node] = true;
	level[node] = l;
	up[node][0] = last;
	for(int i = 1; i<MAXLOG; i++) {
		up[node][i] = up[up[node][i-1]][i-1];
	}
	for(int i = 0; i<(int)G[node].size(); i++) {
		buildLCA(G[node][i], node, l+1, dist[node]);
	}
	return;
}

int eqLevel(int node, int q){
	for(int i = MAXLOG -1; i>=0 && q > 0; i--) {
		if(pot[i] <= q) {
			q -= pot[i];
			node = up[node][i];
		}
	}
	return node;
}

int getLCA(int nodeA, int nodeB) {
	if(level[nodeA] > level[nodeB]) swap(nodeA, nodeB);
	nodeB = eqLevel(nodeB, level[nodeB] - level[nodeA]);
	if(nodeA == nodeB) return nodeA;
	for(int i = MAXLOG -1; i>=0; i--) {
		if(up[nodeA][i] != up[nodeB][i]) {
			nodeA = up[nodeA][i];
			nodeB = up[nodeB][i];
		}
	}
	return up[nodeA][0];
}

int main() {
	pre();
	int n, m;
	while(1) {
		scanf("%d", &n);
		if(n == 0) break;
		for(int i = 0; i<MAXN; i++) {
			G[i].clear();
		}
		memset(dist, 0, sizeof(dist));
		memset(cost, 0, sizeof(cost));
		memset(level, 0, sizeof(level));
		memset(vis, 0, sizeof(vis));
		memset(up, 0, sizeof(up));
		for(int i = 1; i<n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			G[a].push_back(i);
			cost[i] = b;
		}

		buildLCA(0, 0, 0, 0LL);

		scanf("%d", &m);
		for(int i = 0; i<m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			if(a == b) break;
			if(i != 0) printf(" ");
			printf("%lld", dist[a]+dist[b]-2*dist[getLCA(a, b)]);
		}
		printf("\n");
	}


	return 0;
}
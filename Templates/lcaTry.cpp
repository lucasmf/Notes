#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define MAXLOG 15

vector<int> G[MAXN];
int up[MAXN][MAXLOG];
int pot[MAXLOG];
bool vis[MAXN];
int level[MAXN];

void pre() {
	pot[0] = 1;
	for(int i = 1; i<MAXLOG; i++) pot[i] = pot[i-1]*2;
}

void buildLCA(int node, int last, int l) {
	if(vis[node]) return;
	vis[node] = true;
	level[node] = l;
	up[node][0] = last;
	for(int i = 1; i<MAXLOG; i++) {
		up[node][i] = up[up[node][i-1]][i-1];
	}
	for(int i = 0; i<(int)G[node].size(); i++) {
		buildLCA(G[node][i], node, l+1);
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
	freopen("input.txt", "r", stdin);
	pre();
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i<m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	buildLCA(0, 0, 0);

	for(int i = 0; i<n; i++) {
		printf("%d: ", i);
		for(int j = 0; j<MAXLOG; j++) {
			printf("%d ", up[i][j]);
		}
		printf("level: %d", level[i]);
		printf("\n");
	}

	int a, b;
	while(scanf("%d %d", &a, &b) != EOF) {
		if(a == b) break;
		printf("LCA(%d, %d) =  %d\n", a, b, getLCA(a, b));
	}


	return 0;
}
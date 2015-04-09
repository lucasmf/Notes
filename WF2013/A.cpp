#include <bits/stdc++.h>

using namespace std;

//ERRADA!!!

#define MAXN (30*2)

vector<int> G[MAXN];
int vis[MAXN];

bool dfs(int node) {
	if(vis[node] == 1) return true;
	if(vis[node] == 2) return false;
	vis[node] = 1;
	for(int i = 0; i<(int)G[node].size(); i++) {
		if(dfs(G[node][i])) return true;
	}
	vis[node] = 2;
	return false;
}

int main() {
	int n;
	
	scanf("%d", &n);

	for(int i = 0; i<n; i++) {
		int node[4];
		for(int j = 0; j<4; j++) {
			char c1, c2;
			scanf(" %c %c", &c1, &c2);
			if(c1 == '0') node[j] = 0;
			else {
				node[j] = 2*(c1-'A');
				if(c2 == '+') node[j]++;
				else node[j] += 2;
			}
		}
		if(node[0] != 0 && node[2] != 0) {
			if((node[0]&1) == 0) {
				G[node[0]-1].push_back(node[2]);
				//G[node[2]].push_back(node[0]-1);
			}
			else {
				G[node[0]+1].push_back(node[2]);
				//G[node[2]].push_back(node[0]+1);
			}
			if((node[2]&1) == 0) {
				G[node[0]].push_back(node[2]-1);
				//G[node[2]-1].push_back(node[0]);
			}
			else {
				G[node[0]].push_back(node[2]+1);
				//G[node[2]+1].push_back(node[0]);
			}
		}
		if(node[1] != 0 && node[3] != 0) {
			if((node[1]&1) == 0) {
				G[node[1]-1].push_back(node[3]);
				//G[node[3]].push_back(node[1]-1);
			}
			else {
				G[node[1]+1].push_back(node[3]);
				//G[node[3]].push_back(node[1]+1);
			}
			if((node[3]&1) == 0) {
				G[node[1]].push_back(node[3]-1);
				//G[node[3]-1].push_back(node[1]);
			}
			else {
				G[node[1]].push_back(node[3]+1);
				//G[node[3]+1].push_back(node[1]);
			}
		}
	}

	for(int i = 0; i<MAXN; i++) {
		printf("%d: ", i);
		for(int j = 0; j<(int)G[i].size(); j++) {
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}

	bool hasCicle = false;

	memset(vis, 0, sizeof(vis));

	for(int i = 0; i<MAXN; i++) {
		if(vis[i] == 0) hasCicle |= dfs(i);
	}

	printf("%s\n", hasCicle?"unbounded":"bounded");
	return 0;
}
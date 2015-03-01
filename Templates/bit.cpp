#include <bits/stdc++.h>

using namespace std;

#define MAXN 1100000

int parent[MAXN];
int rank[MAXN];

void pre() {
	for(int i = 0; i<MAXN; i++) parent[i] = i;
		memset(rank, 0, sizeof(rank));
}

int read(int a) {
	return a == parent[a]?a:parent[a] = read(parent[a]);
}

bool join(int a, int b) {
	int nodeA = read(a);
	int nodeB = read(b);
	if(nodeA == nodeB) return false;
	if(rank[nodeA] > rank[nodeB]) {
		rank[nodeA]++;
		parent[nodeB] = nodeA;
	}
	else {
		rank[nodeB]++;
		parent[nodeA] = nodeB;
	}
	return true;
}

int main() {
	pre();

	int n;
	printf("Numero de nos:\n");
	scanf("%d", &n);
	
	int qOp;
	printf("Numero de operacoes:\n");
	scanf("%d", &qOp);

	for(int i = 0; i<n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if(join(a, b))
			printf("Nos unidos com sucesso!\n");
		else 
			printf("Nos ja unidos\n");
	}
	return 0;
}
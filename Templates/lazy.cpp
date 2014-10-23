#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define left (2*node + 1)
#define right (2*node + 2)
#define mid ((ini+fim)/2)


//NOT TESTED

struct seg{
  int sum;
  int flag;
};

seg T[MAXN * 4];

void doLazy(int node, int ini, int fim) {
	if( T[node].flag ) {
    	T[node].sum += (fim - ini + 1) * T[node].flag;
    	if( ini != fim ) {
      		T[left].flag += T[node].flag;
      		T[right].flag += T[node].flag;
    	}
    	T[node].flag = 0;
  	}
}

void update(int i, int j, int node, int ini, int fim, int valor) {
  	doLazy(node,ini,fim);
  	if( i > fim || j < ini || ini > fim || i > j ) return;
  	if( i <= ini && j >= fim ) {
		T[node].flag += valor;
  	  	doLazy(node,ini,fim);
    	return;
  	}
  	update(i,j,left,ini,mid,valor);
  	update(i,j,right,mid+1,fim,valor);
  	T[node].sum = T[left].sum + T[right].sum;
}

int get( int i, int j,  int node, int ini, int fim) {
  	doLazy(node,ini,fim);
  	if( i > fim || j < ini || ini > fim ) return 0;
  	if( i <= ini && j >= fim ) return T[node].sum;
  	return get(i,j,left,ini,mid) + get(i,j,right,mid+1,fim);
}

int main() {
	return 0;
}

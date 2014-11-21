#include <bits/stdc++.h>

using namespace std;

#define MAXN 210

//AC, finalmente!

int grid[MAXN][MAXN];
int color[MAXN][MAXN];
set<int> adj[MAXN*MAXN];
vector<int> blacks;
int r[8];
map<char, string> mm;

void add(int x, int y, char c) {
      string str = mm[c];
      grid[x][y] = str[0] - '0';
      grid[x][y+1] = str[1] - '0';
      grid[x][y+2] = str[2] - '0';
      grid[x][y+3] = str[3] - '0';
}

void dfs(int x, int y, int v) {
	if(x < 0 || x >= MAXN || y < 0 || y >= MAXN) return;
	if(color[x][y] != 0) return;
	color[x][y] = v;
	if(grid[x][y] == grid[x+1][y]) dfs(x+1, y, v);
	if(grid[x][y] == grid[x-1][y]) dfs(x-1, y, v);
	if(grid[x][y] == grid[x][y+1]) dfs(x, y+1, v);
	if(grid[x][y] == grid[x][y-1]) dfs(x, y-1, v);

}


int main() {
      mm['0']="0000";
      mm['1']="0001";
      mm['2']="0010";
      mm['3']="0011";
      mm['4']="0100";
      mm['5']="0101";
      mm['6']="0110";
      mm['7']="0111";
      mm['8']="1000";
      mm['9']="1001";
      mm['a']="1010";
      mm['b']="1011";
      mm['c']="1100";
      mm['d']="1101";
      mm['e']="1110";
      mm['f']="1111";
      int teste = 1;
      int h, w;
      int idx;
      while(scanf("%d %d", &h, &w) > 0 && h != 0){

	   
	    if(h == 0 || w == 0) break;
		idx = 1;
	    
	    blacks.clear();
	    for(int i = 0; i<MAXN; i++) {
		  for(int j = 0; j<MAXN; j++) {
			grid[i][j] = 0;
			color[i][j] = 0;
		  }
	    }
	    for(int i = 0; i<MAXN*MAXN; i++) {
			adj[i].clear();
		}
	    for(int i = 0; i<8; i++) r[i] = 0;

	    for(int i = 1; i<=h; i++) {
		  for(int j = 1; j<4*w; j+=4) {
			char c;
			scanf(" %c", &c);
			add(i, j, c);
		  }
	    }
	    for(int i = 0; i<=h; i++) {
			for(int j = 0; j<=4*w; j++) {
				if(color[i][j] == 0) {
					if(grid[i][j] == 1) {
						blacks.push_back(idx);
					}
					dfs(i, j, idx++);	
				}
				
			}
		}
		
	    for(int i = 1; i<=h; i++) {
		  for(int j = 1; j<=4*w; j++) {
			if(grid[i][j] == 1) {
			      adj[color[i][j]].insert(color[i][j]);
			      adj[color[i][j]].insert(color[i+1][j]);
			      adj[color[i][j]].insert(color[i-1][j]);
			      adj[color[i][j]].insert(color[i][j+1]);
			      adj[color[i][j]].insert(color[i][j-1]);
			}
		  }
	    }
	    for(int i = 0; i<(int)blacks.size(); i++) {
			//printf(">>%d\n", adj[blacks[i]].size());
			r[adj[blacks[i]].size()]++;
	    }
	    printf("Case %d: ", teste++);
	    for(int i = 0; i<r[3]; i++) printf("A");
	    for(int i = 0; i<r[7]; i++) printf("D");
	    for(int i = 0; i<r[5]; i++) printf("J");
	    for(int i = 0; i<r[4]; i++) printf("K");
	    for(int i = 0; i<r[6]; i++) printf("S");
	    for(int i = 0; i<r[2]; i++) printf("W");
	    printf("\n");
      }
   
      return 0;
}

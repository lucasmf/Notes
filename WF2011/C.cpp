#include <bits/stdc++.h>

using namespace std;

#define MAXN 210

//Nao testado, submission failed

int grid[MAXN][MAXN];
int color[MAXN][MAXN];
set<int> adj[MAXN*MAXN];
vector<int> blacks;
int r[7];
map<char, string> mm;

void add(int x, int y, char c) {
      string str = mm[c];
      grid[x][y] = str[0] - '0';
      grid[x][y+1] = str[1] - '0';
      grid[x][y+2] = str[2] - '0';
      grid[x][y+3] = str[3] - '0';
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
      while(1) {

	    int h, w;
	    scanf("%d %d", &h, &w);
	    if(h == 0 || w == 0) break;
   
	    int idx = 1;
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
	    for(int i = 0; i<7; i++) r[i] = 0;

	    for(int i = 1; i<=h; i++) {
		  for(int j = 1; j<=w; j++) {
			char c;
			scanf(" %c", &c);
			add(i, j, c);
		  }
	    }
	    for(int i = 1; i<MAXN; i++) {
			for(int j = 1; j<MAXN; j++) {
				if(grid[i-1][j] == grid[i][j]) {
					color[i][j] = color[i-1][j];
				}
				else if(grid[i][j-1] == grid[i][j]) {
					color[i][j] = color[i][j-1];
				}
				else {
					if(grid[i][j] == 1) blacks.push_back(idx);
					color[i][j] = idx++;
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
		  r[adj[blacks[i]].size()]++;
	    }
	    printf("Case: %d: ", teste++);
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

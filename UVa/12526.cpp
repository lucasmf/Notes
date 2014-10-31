#include <bits/stdc++.h>

using namespace std;

#define MAXN 100100

//testado

struct node {
	map<char, node> mm;
	node() {}
	void insert(string str, int idx) {
		if(idx == (int)str.size()) {
			mm['$'] = node();
			return;
		}
		mm[str[idx]].insert(str, idx+1);
	}
	int count(string str, int idx) {
		if(idx == (int)str.size()) return 0;
		if(mm.size() >1 || idx == 0) return 1 + mm[str[idx]].count(str, idx+1);
		return mm[str[idx]].count(str, idx+1);
	}
	
};

vector<string> v;

int main() {
	int n;
	node root;
	int r = 0;
	while(scanf("%d", &n) != EOF) {
		root = node();
		v.clear();
		r = 0;
		for(int i = 0; i<n; i++) {
			string str;
			cin >> str;
			root.insert(str, 0);
			v.push_back(str);
		}
		for(int i = 0; i<n; i++) {
			r += root.count(v[i], 0);
		}
		printf("%.2lf\n", (double)r/n);
	}
	return 0;
}

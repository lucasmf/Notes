#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("cooking_the_books.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	int test = 1;
	scanf("%d", &t);
	while(t--) {
		string n;
		cin >> n;
		
		for(int j = 0; j<(int)n.size(); j++) {
			pair<char, int> minimum = make_pair(n[j], 0);
		    
			for(int i = 1; i<(int)n.size(); i++) {
				if(n[i] != '0') {
				minimum = min(minimum, make_pair(n[i], i));
				
				}
			}
			if(minimum.first != n[j]) {
				break;
			}
			
		}

for(int j = 0; j<(int)n.size(); j++) {
			
		    pair<char, int> maximum = make_pair(n[j], 0);
			for(int i = 1; i<(int)n.size(); i++) {
				if(n[i] != '0') {
				
				maximum = max(maximum, make_pair(n[i], i));
				}
			}
			
		}

		
		string nMin = n;
		string nMax = n;
		swap(nMin[0], nMin[minimum.second]);
		swap(nMax[0], nMax[maximum.second]);

		printf("Case #%d: %s %s\n", test++, nMin.c_str(), nMax.c_str());

	}
	return 0;
}
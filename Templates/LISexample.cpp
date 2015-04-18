#include <bits/stdc++.h>

using namespace std;

map<char, int> m;
vector<int> v;

int main() {
	string A, B;
	cin >> A >> B;
	int* idx= new int(0);
	for(int i = 0; i<(int)A.size(); i++) {
		if(m.find(A[i]) == m.end()) m[A[i]] = (*idx)++;	
		printf("%d ", m[A[i]]);
	}
	delete(idx);
	for(int i = 0; i<(int)B.size(); i++) {
		v.push_back(m[B[i]]);
	}

	return 0;
}
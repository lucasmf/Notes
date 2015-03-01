#include <bits/stdc++.h>

using namespace std;

void rec(int i) {
	if(i == 200000) return;
	rec(i+1);
}

int main() {
	rec(0);
	return 0;
}
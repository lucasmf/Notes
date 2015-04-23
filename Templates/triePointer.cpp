#include <bits/stdc++.h>

using namespace std;

struct trie {
	map<char, trie*> m;

	trie(){}

	void addWord(char* word) {
		if(m.find(*word) == m.end()) m[*word] = new trie();
		if(*word)m[*word]->addWord(word+1);
	} 

	bool hasWord(char* word) {
	
		if(m.find(*word) == m.end()) return false;
		if(!*word) return true;
		return (m[*word])->hasWord(word+1);
	}
};

int main() {
	trie* root = new trie();
	char str[] = "aa", str2[] = "a";
	root->addWord(str);
	printf("%d\n", root->hasWord(str));
	printf("%d\n", root->hasWord(str2));
	return 0;
}
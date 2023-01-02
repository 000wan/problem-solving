#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	
	int X[N];
	map<int, int> Y;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
		Y[X[i]] ++;
	}
	
	unordered_map<int,int> table;
	map<int,int>::iterator iter;
	int index = 0;
	
	for(iter = Y.begin(); iter != Y.end(); ++iter) {
		table[iter->first] = index++;
	}
	
	for (int i = 0; i < N; i++) {
		cout << table[X[i]] << ' ';		
	}
}

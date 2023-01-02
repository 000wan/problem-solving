#include <bits/stdc++.h>
using namespace std;

void solve() {
	int k;
	cin >> k;
	
	map<int,int> rb;
	
	while (k--) {
		char cmd;
		int x;
		cin >> cmd >> x;
		
		if (cmd == 'I') {
			rb[x]++;
		}
		else if (cmd == 'D') {
			if (rb.empty())
				continue;
			
			if (x == 1) {
				map<int,int>::iterator M;
				M = --rb.end();
				
				if ((--rb[M->first]) == 0) {
					rb.erase(M);
				}
			}
			else if (x == -1) {
				map<int,int>::iterator m;
				m = rb.begin();
				
				if ((--rb[m->first]) == 0) {
					rb.erase(m);
				}
			}
		}
	}
	
	if (rb.empty()) {
		cout << "EMPTY" << '\n';
		return;	
	}
	
	map<int,int>::iterator M;
	M = --rb.end();
	
	map<int,int>::iterator m;
	m = rb.begin();
	
	cout << M->first << ' ' << m->first << '\n';
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;
	cin >> T;
	
	while (T--) {
		solve();
	}
}

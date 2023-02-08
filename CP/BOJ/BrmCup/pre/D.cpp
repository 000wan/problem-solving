// Not completed

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(int N, int M) {
	unordered_map<pair<int,int>, bool> s;
	
	for(int r = 0; r < N; r++) {
		int x;
		cin >> x;
		
		if (x == 0)
			continue;
		
		int start = 0;
		for(int j = 0; j < x; j++) {
			int c;
			char d;
			cin >> c >> d;
			c--;
			
			if (d == 'R') {
				start = c;
			}
			else if (d == 'L') {
				for(int k = start; k <= c; k++) {
					s.insert(make_pair(make_pair(r, k), true));
				}
				start = -1;
			}
		}
		
		if (start != -1) {
			for(int k = start; k < M; k++) {
				s.insert(make_pair(make_pair(r, k), true));
			}
			start = -1;
		}
	}
	
	bool flag[max(N, M)];
	for (int z = 0; z <= N+M-2; z++) {
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	solve(N, M);
	
	return 0;
}


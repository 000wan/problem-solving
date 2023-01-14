#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define SUP 1000000

void solve(int N) {	
	int x[N];
	unordered_map<int, int> res;
	bool P[SUP+1] = {};
	
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		P[x[i]] = true;
	}
	
	for (int i = 0; i < N; i++) {
		int xi = x[i];
		int j = 2;
		
		while (xi*j <= SUP) {
			if (P[xi*j]) {
				res[xi]++;
				res[xi*j]--;
			}
			j++;
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << res[x[i]] << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	solve(N);
	
	return 0;
}


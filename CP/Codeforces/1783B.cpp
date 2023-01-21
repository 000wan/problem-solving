#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	int n;
	cin >> n;
	
	int c = 2;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if (i == 0) {
				if (j == 0) {
					cout << 1 << ' ';
					continue;
				}
				if (j == 1) {
					cout << n*n << ' ';
					continue;
				}
			}
			
			cout << c++ << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	
	while (T--)
		solve();
	
	return 0;
}


#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	int res = 0;
	int prev = -1;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		
		if (prev+1 != x) {
			res += x;
		}
		prev = x;
	}
	
	cout << res;
	
	return 0;
}


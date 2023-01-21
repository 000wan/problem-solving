#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	int n;
	cin >> n;
	
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	const int INF = (int)1e8;
	
	int res = 0;
	int dp[n][2];
	
	for (int i=0; i<n; i++)
		dp[i][0] = dp[i][1] = INF;
	
	if (a[0]%2 == 1)
		dp[0][1] = 0;
	else
		dp[0][0] = 0;
	
	
	for (int i=1; i<n; i++) {		
		if (a[i]%2 == 1) {
			if (dp[i-1][0] != INF)
				dp[i][0] = dp[i-1][0] + 1;
			dp[i][1] = min(dp[i-1][1] + 1, dp[i-1][0]);
		}
		else { // even
			
			dp[i][0] = min(dp[i-1][0] + 1, dp[i-1][1]);
		}
	}
	
	cout << min(dp[n-1][0], dp[n-1][1]) << '\n';
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


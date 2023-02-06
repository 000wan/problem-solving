#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(string s1, string s2) {
	int N = s1.length();
	int M = s2.length();
	
	int dp[N+1][M+1] = {};
	
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	return dp[N][M];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s1;
	cin >> s1;
		
	string s2;
	cin >> s2;
	
	cout << solve(s1, s2);
	
	return 0;
}


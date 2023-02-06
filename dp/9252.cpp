#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(string s1, string s2) {
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

    cout << dp[N][M] << '\n';

    std::stack<int> sol;
    int i = N, j = M;
    while (i >= 1 && j >= 1) {
        if (dp[i][j] == dp[i-1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j-1]) {
            j--;
        } else if (dp[i][j] == dp[i-1][j-1]+1) {
            sol.emplace(i-1);
            i--, j--;
        }
    }
    while (!sol.empty()) {
        cout << s1[sol.top()];
        sol.pop();
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s1;
	cin >> s1;
		
	string s2;
	cin >> s2;
	
    solve(s1, s2);
	
	return 0;
}


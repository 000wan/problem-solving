#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAX_N 1024

int A[MAX_N+1][MAX_N+1];
int dp[MAX_N+1][MAX_N+1] = {};

void prefix_sum(int N) {
	for (int i=1; i<=N; ++i)
		for (int j=1; j<=N; ++j)
			dp[i][j] = A[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
}

int partial_sum(int x1, int y1, int x2, int y2) {
	return dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];  
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	for (int i=1; i<=N; ++i)
		for (int j=1; j<=N; ++j)
			cin >> A[i][j];
	
	prefix_sum(N);
	for (int i=0; i<M; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << partial_sum(x1, y1, x2, y2) << '\n';
	}
	
	return 0;
}


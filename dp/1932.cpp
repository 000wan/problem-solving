#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500

int solve(int A[][MAX_N], int N) {
	int dp[N][N];
	dp[0][0] = A[0][0];
	
	for (int i = 1; i < N; i++) {
		dp[i][0] = dp[i-1][0] + A[i][0];
		dp[i][i] = dp[i-1][i-1] + A[i][i];
		
		for (int j = 1; j < i; j++) {
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + A[i][j];
		}
	}
	
	int res = -1;
	for (int i = 0; i < N; i++) {
		res = max(res, dp[N-1][i]);
	}
	
	return res;
}

int main(void) {
	int N;
	cin >> N;
	
	int A[N][MAX_N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> A[i][j];
		}
	}
	
	cout << solve(A, N);
}

#include <bits/stdc++.h>
using namespace std;

int solve(int A[][3], int N) {
	int dp[N][3];
	dp[0][0] = A[0][0];
	dp[0][1] = A[0][1];
	dp[0][2] = A[0][2];
	
	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + A[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + A[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + A[i][2];
	}
	
	return min(min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);
}

int main(void) {
	int N;
	cin >> N;
	
	int A[N][3];
	for (int i = 0; i < N; i++) {
		cin >> A[i][0] >> A[i][1] >> A[i][2];
	}
	
	cout << solve(A, N);
}

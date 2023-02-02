#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int solve(int A[][3], int N) {
	int dp[N][3][3];
	
    for (int start = 0; start < 3; ++start) {
        dp[0][0][start] = dp[0][1][start] = dp[0][2][start] = INF;
        dp[0][start][start] = A[0][start];
        
        for (int i = 1; i < N; i++) {
            dp[i][0][start] = min(dp[i-1][1][start], dp[i-1][2][start]) + A[i][0];
            dp[i][1][start] = min(dp[i-1][0][start], dp[i-1][2][start]) + A[i][1];
            dp[i][2][start] = min(dp[i-1][0][start], dp[i-1][1][start]) + A[i][2];
        } 
    }
    
    int res = INF;
    for (int i = 0; i < 9; ++i) {
        if (i % 4)
            res = min(res, dp[N-1][i/3][i%3]);
    }
    return res;
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

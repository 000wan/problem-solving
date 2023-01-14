#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int N, int A[]) {
	int dp[N] = {};
	
	for (int i = 0; i < N; ++i) {
		int M = 0;
		for (int j = 0; j < i; ++j) {
			if (A[j] < A[i]) {
				M = max(M, dp[j]);
			}
		}
		dp[i] = M + A[i];
	}
	
	int res = -1;
	for (int i = 0; i < N; ++i)
		res = max(res, dp[i]);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	int A[N];
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	
	cout << solve(N, A);
	
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100
#define MAX_K 100000

int W[MAX_N], V[MAX_N];

int memo[MAX_N][MAX_K+1];
int knapsack(int i, int k, int N) {
	if (i >= N) {
		return 0;
	}
	if (memo[i][k]) {
		return memo[i][k];
	}
	
	int res = knapsack(i+1, k, N);
	if (k >= W[i]) {
		res = max(res, V[i] + knapsack(i+1, k-W[i], N));
	}
	
	memo[i][k] = res;
	return memo[i][k];
}

int main(void) {
	int N, K;
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		cin >> W[i] >> V[i];
	}
	
	cout << knapsack(0, K, N);
}

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1400
#define MAX_C 10000

vector<int> V, W;

// 0-1 knapsack, O(NC)
int memo[MAX_N][MAX_C+1];
int knapsack(int i, int k) {
	if (i >= V.size()) 
		return 0;
	if (memo[i][k] != -1)
		return memo[i][k];
	
	int res = knapsack(i+1, k);
	if (k >= W[i])
		res = max(res, V[i] + knapsack(i+1, k-W[i]));
	memo[i][k] = res;
	return memo[i][k];
}

// bounded knapsack: O(NClogK)
int bounded_knapsack(int N, int C, vector<int>& vi, vector<int>& wi, vector<int>& ki) {
	for (int i = 0; i < N; ++i) {
		int l = __builtin_clz(0)-__builtin_clz(ki[i])-1;
		for (int t = 0; t < l; ++t) {
			V.push_back((1<<t) * vi[i]);
			W.push_back((1<<t) * wi[i]);
		}
		V.push_back((ki[i]-((1<<l)-1)) * vi[i]);
		W.push_back((ki[i]-((1<<l)-1)) * wi[i]);
	}
	return knapsack(0, C);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	fill(&memo[0][0], &memo[MAX_N-1][MAX_C+1], -1);

	int N, C;
	cin >> N >> C;
	
	vector<int> vi(N), wi(N), ki(N);
	for (int i = 0; i < N; i++) {
		cin >> wi[i] >> vi[i] >> ki[i];
	}
	
	cout << bounded_knapsack(N, C, vi, wi, ki);
	return 0;
}

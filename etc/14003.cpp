#include <bits/stdc++.h>
#define ll long long
using namespace std;

void LIS(int N, int A[]) {
	vector<int> v;
	int dp[N] = {};
	
	for (int i = 0; i < N; ++i) {
		int a = A[i];
		auto iter = lower_bound(v.begin(), v.end(), a);
		
		if (iter == v.end()) {
			v.push_back(a);
			dp[i] = v.size();
		} else {
			*iter = a;
			dp[i] = iter - v.begin() + 1;
		}
	}
	
	int res = v.size();
	cout << res << '\n';
	
	stack<int> sol;
	for (int i = N-1; i >= 0; --i) {
		if (dp[i] == res) {
			sol.push(i);
			res--;
		}
		
		if (res == 0)
			break;
	}
	
	while (!sol.empty()) {
		cout << A[sol.top()] << ' ';
		sol.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	int A[N];
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	
	LIS(N, A);
	
	return 0;
}


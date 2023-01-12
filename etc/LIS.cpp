#include <bits/stdc++.h>
#define ll long long
using namespace std;

int LIS(int start, int stop, int A[], int sign) { // sign +1: increasing, -1: decreasing
	if (start >= stop)
		return 0;

	vector<int> v;
	
	for (int i = start; i < stop; ++i) {
		int a = sign * A[i];
		auto iter = lower_bound(v.begin(), v.end(), a);
		
		if (iter == v.end()) {
			v.push_back(a);
		} else {
			*iter = a;
		}
	}
	
	return v.size();
}

// Longest Bitonic increasing sequence
int BIS(int start, int stop, int N, int A[], int sign, int last) { // sign +1: increasing, -1: decreasing
	if (start > stop)
		return 0;
	if (start == stop)
		return BIS(stop, N, N, A, -sign, INT_MIN);

	vector<int> v;
	
	for (int i = start; i < stop; ++i) {
		if (A[i] == last)
			continue;
			
		int a = sign * A[i];
		auto iter = lower_bound(v.begin(), v.end(), a);
		
		if (iter == v.end()) {
			v.push_back(a);
		} else {
			*iter = a;
		}
	}
	
	int res = v.size();
	if (sign > 0) {
		res += BIS(stop, N, N, A, -sign, v.back());
	}
	return res;
}

int Bitonic(int A[], int N) {
	int res = 0;
	
	for (int i = 0; i < N; ++i) {
		res = max(res, BIS(0, i, N, A, 1, INT_MIN));
	}
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
	
	cout << Bitonic(A, N);
	
	return 0;
}


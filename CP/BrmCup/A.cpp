#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int N, int A, int B, int C) {
	int res = 0;
	if (A >= N)
		res += N;
	else
		res += A;
		
	if (B >= N)
		res += N;
	else
		res += B;
		
	if (C >= N)
		res += N;
	else
		res += C;
		
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	int A, B, C;
	cin >> A >> B >> C;
	
	cout << solve(N,A,B,C);
	
	return 0;
}


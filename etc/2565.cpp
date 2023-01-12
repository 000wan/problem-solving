#include <bits/stdc++.h>
#define ll long long
using namespace std;

int LIS(map<int,int> A) {
	vector<int> v;
	
	for (auto i = A.begin(); i != A.end(); ++i) {
		int a = i->second;
		auto iter = lower_bound(v.begin(), v.end(), a);
		
		if (iter == v.end()) {
			v.push_back(a);
		} else {
			*iter = a;
		}
	}
	
	return v.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	map<int,int> A;
	for (int i = 0; i < N; ++i) {
		int a,b;
		cin >> a >> b;
		A[a] = b;
	}
	
	cout << N - LIS(A);
	
	return 0;
}


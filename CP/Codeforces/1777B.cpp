#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MOD 1000000007
#define MAX_N (int)1e5

ll fact[MAX_N+1];
void factorial() {
	fact[0] = 1;
	for (int i=1; i<=MAX_N; i++)
		fact[i] = (fact[i-1] * i) % MOD;
}

void solve() {
	ll n;
	cin >> n;
	
	ll res = (n*(n-1)) % MOD;
	res = (res * fact[n]) % MOD;
	
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	factorial();
	
	int t;
	cin >> t;
	
	while (t--)
		solve();
	
	return 0;
}


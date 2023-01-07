// Fast Binomial Coefficients
// Ref: https://rebro.kr/107

#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define N_MAX 4000000
#define P 1000000007

ll fac[N_MAX+1], fac_inv[N_MAX+1], inv[N_MAX+1];

void factorial(int p, int M) {
	fac[0] = 1;
	fac_inv[0] = 1;
	inv[1] = 1;
	
	for (int i = 1; i <= M; i++) {
		if (i >= 2) {
			inv[i] = ( -(p/i) * inv[p % i] ) % p;
			inv[i] = (p + inv[i]) % p;
		}
		
		fac[i] = (fac[i-1] * i) % p;
		fac_inv[i] = (fac_inv[i-1] * inv[i]) % p;
	}
}

int fast_binom_coeff(int N, int K, int p) {
	ll res = (fac[N] * fac_inv[N-K] % p) * fac_inv[K] % p;
	return res % p;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	factorial(P, N_MAX);
	
	int T;
	cin >> T;
	
	while (T--) {
		int N, K;
		cin >> N >> K;
		
		cout << fast_binom_coeff(N, K, P) << '\n';
	}
}

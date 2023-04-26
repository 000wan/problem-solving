#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

#define pii pair<int,int>
pii xGCD(int a, int b) {
	int r1 = a, s1 = 1;
	int r = b, s = 0;
	while (r != 0) {
		int q = r1 / r, r0 = r, s0 = s;
		r = r1 - q*r; r1 = r0;
		s = s1 - q*s; s1 = s0;
	}
	return {s1, (r1 - a*s1)/b};
}
int mod_inv(int a, int mod) {
	int b = xGCD(a, mod).first % mod;
	return (b + mod) % mod;
}

const int MOD = 1e9+7;
const int MAX_N = 3000;
ll fac[MAX_N+1], inv[MAX_N+1], fac_inv[MAX_N+1], D[MAX_N+1];
void init() {
    fac[0] = fac_inv[0] = inv[1] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        fac[i] = (i*fac[i-1]) % MOD;
        if (i > 1) inv[i] = (-MOD/i*inv[MOD%i]%MOD + MOD) % MOD;
        fac_inv[i] = (inv[i]*fac_inv[i-1]) % MOD;
    }
    D[0] = D[1] = 1;
    for (int n = 2; n <= MAX_N; ++n) {
        for (int i = 0; i <= n-1; i += 2) {
            D[n] += D[i]*D[n-1-i]%MOD * fac[n-1]%MOD*fac_inv[i]%MOD*fac_inv[n-1-i]%MOD;
            D[n] %= MOD;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    init();
    int N, n, m;
    cin >> N >> n;
    int a[N], b[N];
    for (int i = 0, x; i < N; ++i) {
        cin >> x;
        if (x == 1) a[i] = 1;
        else a[i] = 0, a[i+1] = 1, i++;
    }
    cin >> m;
    for (int i = 0, x; i < N; ++i) {
        cin >> x;
        if (x == 1) b[i] = 1;
        else b[i] = 0, b[i+1] = 1, i++;
    }
    
    ll res = 0, sol = 1;
    int suml = 0, prev = -1;
    for (int i = 0; i < N; ++i) {
        if (a[i] == b[i]) {
            int nl = i-1-prev;
            sol = sol * D[nl]%MOD * fac_inv[nl]%MOD;
            suml += nl;
            prev = i;
        } else {
            res ++;
        }
    }
    sol = (sol * fac[suml]) % MOD;
    cout << res << ' ' << sol << '\n';

    return 0;
}
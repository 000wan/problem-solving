#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define P1 97
#define P2 1031

int binomial[2][1032][1032];

void binom_coef(int M) {
	int flag = (int)(M == P2);
	binomial[flag][0][0] = 1;
		
    for (int i = 1; i <= M; i++) {
    	int* prev = binomial[flag][i-1];
        int* next = binomial[flag][i];
        
        next[0] = next[i] = 1;
        for(int j=1; j<=i-1; j++) {
            next[j] = prev[j-1] + prev[j];
            next[j] %= M;  // mod M
        }
    }
}

int lucas_thm(long long m, long long n, int p) {
	if (m < n) {
		return 0;
	}
	if (m <= p && n <= p) {
		int flag = (int)(p == P2);
		return binomial[flag][m][n];
	}
	
	int mi[60] = {};
	int ni[60] = {};
	
	int k = 0;
	while (m>0) {
		mi[k++] = m%p;
		m = m/p;
	}
	
	int l = 0;
	while (n>0) {
		ni[l++] = n%p;
		n = n/p;
	}
	
	int res = 1;
	for (int i = 0; i < k; i++) {
		res *= lucas_thm(mi[i], ni[i], p);
		res %= p;
	}
	
	return res;
}

int* xGCD(int a, int b) {  // extended euclidean
	int old_r = a;
	int old_s = 1;
	int r = b;
	int s = 0;
	
	while (r != 0) {
		int q = old_r / r;
		int tmp_r = r;
		int tmp_s = s;
		
		r = old_r - q*r;
		old_r = tmp_r;
		s = old_s - q*s;
		old_s = tmp_s;
	}
	
	int* res = new int[3];
	res[0] = old_s;
	res[1] = (old_r - a*old_s)/b;
	res[2] = old_r;
	return res;
}

int mult_inverse(int a, int m) {  // multiple inverse (modulo m)
	int b = xGCD(a,m)[0] % m;
	if (b < 0)
		b = (b + m) % m;
	return b;  // mod m
}

// CRT for coprimes
ll CRT(int a[], int n[], int k) {
	ll M = 1;
	for (int i = 0; i < k; i++) {
		M *= n[i];
	}
	
	ll res = 0;
	for (int i = 0; i < k; i++) {
		ll Mi = M/n[i];
		res += a[i] * Mi * mult_inverse(Mi, n[i]);
		res %= M;
	}
	
	return res;  // x = res (mod M)
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	binom_coef(P1);
	binom_coef(P2);
	int T;
	cin >> T;
	
	int P[2] = { P1, P2 };
	
	while(T--) {
		int N, M;
		cin >> N >> M;
		
		if (M == 1) {
			cout << (int)(N == 0) << '\n';
			continue;
		}
		
		int a[2];
		a[0] = lucas_thm(N-1, M-2, P1);
		a[1] = lucas_thm(N-1, M-2, P2);
		
		cout << CRT(a, P, 2) << '\n';
	}
}

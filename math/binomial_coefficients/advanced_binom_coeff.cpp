// Arithmetic properties of Binomial Coefficients
// Ref: https://dms.umontreal.ca/~andrew/Binomial/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define PQ 27

int* xGCD(int a, int b);
int mult_inverse(int a, int m);

// p-adic factorial
int p_fac[PQ], p_fac_inv[PQ];

void p_factorial(int p, int q, int M) {
	int pq = pow(p, q);
	
	p_fac[0] = 1;
	p_fac_inv[0] = 1;
	
	for (int i = 1; i < M; i++) {
    	if (i % p == 0) {
    		p_fac[i] = p_fac[i-1] % pq;
		} else {
			p_fac[i] = (p_fac[i-1] * i) % pq;		
    	}
    	
    	p_fac_inv[i] = mult_inverse(p_fac[i], pq);
	}
}

ll binom_coeff_mod_prime_power(ll n, ll m, int p, int q) {
	// Get number of carries (e_j) adding m and r
	int e_0 = 0;
	int e_q1 = 0;
	
	ll n_tmp = n;
	ll m_tmp = m;
	ll r_tmp = n - m;
	
	int d = 0;
	while (n_tmp > 0) {
		n_tmp /= p;
		d++;
	}
	
	int mr_i[60] = {};
	
	int k = 0;
	while (m_tmp > 0) {
		mr_i[k++] += m_tmp % p;
		m_tmp /= p;
	}
	
	int l = 0;
	while (r_tmp > 0) {
		mr_i[l++] += r_tmp % p;
		r_tmp /= p;
	}
	
	int carry = 0;
	for (int k = 0; k < 60; k++) {		
		mr_i[k] += carry;
		carry = mr_i[k] / p;
		mr_i[k] %= p;
		
		if (carry) {
			e_0 ++;
			if (k >= q-1) {
				e_q1 ++;
			}
		}
	}
	
	// Caclulate Prod_( Nj choose Mj ) in p-adic
	int pq = pow(p, q);
	n_tmp = n;
	m_tmp = m;
	r_tmp = n - m;
	
	ll prod = 1;
	
	for (int i = 0; i < d; ++i) {
		int Nj = n_tmp % pq;
		int Mj = m_tmp % pq;
		int Rj = r_tmp % pq;
		
		prod *= p_fac[Nj] * p_fac_inv[Mj] * p_fac_inv[Rj];
		prod %= pq;
		
		n_tmp /= p;
		m_tmp /= p;
		r_tmp /= p;
	}
	
	int sign;
	if (p == 2 && q >= 3) {
		sign = 1;
	} else {
		sign = pow(-1, e_q1);
	}
	prod *= sign * pow(p, e_0);
	prod = (prod % pq + pq) % pq;
	
	return prod;
}

// Multiple inverse by xGCD
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
	if (b < 0) {
		b = (b + m) % m;
	}
	return b;  // mod m
}

int main(void) {
	p_factorial(3, 3, 27);
	
	int T;
	cin >> T;
	
	while (T--) {
		int N, K;
		cin >> N >> K;
		cout << binom_coeff_mod_prime_power(N, K, 3, 3) << '\n';
	}
}

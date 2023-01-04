#include <bits/stdc++.h>
#define ll long long
using namespace std;

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
	return xGCD(a,m)[0] % m;  // mod m
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

// CRT for non-coprimes
// Ref : https://math.stackexchange.com/q/1644677
ll xCRT(int a[], int n[], int k) {  
	ll a1 = a[0];
	ll n1 = n[0];
	
	for (int i = 1; i < k; i++) {
		int* g = xGCD(n1, n[i]);
		
		if ((a1 - a[i]) % g[2] != 0) {  // solution doesn't exist
			a1 = -1;
			break;
		}
		
		ll lcm = ( n1 * n[i] ) / g[2];
		ll lambda = ( a1 - a[i] ) / g[2];
		ll sigma = ( a1 - n1*g[0]*lambda ) % lcm;
		if (sigma < 0) {
			sigma = (sigma + lcm) % lcm;
		}
		
		a1 = sigma;
		n1 = lcm;
	}
	
	return a1;
}

/*  BOJ #12971  */
int main(void) {
	int p[3];
	int x[3];
	
	cin >> p[0] >> p[1] >> p[2] >> x[0] >> x[1] >> x[2];
	cout << xCRT(x, p, 3);
}

/*  BOJ #6064  */
int main(void) {
	int T;
    cin >> T;
    
    while(T--) {
      int p[2];
	    int x[2];
	    cin >> p[0] >> p[1] >> x[0] >> x[1];
	    x[0]--;
	    x[1]--;
        
			ll res = xCRT(x, p, 2);
			if (res == -1) {
				cout << res << '\n';
			} else {
				cout << 1+res << '\n';
			}
    }
}

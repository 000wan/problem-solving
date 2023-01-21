#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MOD 1000000007

typedef vector<vector<ll>> matrix;

matrix operator * (matrix& A, matrix& B) {
	matrix C(2, vector<ll>(2));
	
	for (int i=0; i<2; ++i) {
		for (int j=0; j<2; ++j) {
			for (int k=0; k<2; ++k) {
				C[i][j] += A[i][k] * B[k][j];
				C[i][j] %= MOD;
			}
		}
	}
	return C;
}

ll fibo_power(ll n) {
	matrix res = {{1, 0}, {0, 1}};
	matrix A = {{1, 1}, {1, 0}};
	
	while (n > 0) {
		if (n & 1)
			res = A * res;
		
		A = A * A;
		n = n >> 1;
	}
	
	return res[1][0];
}

vector<int> fibo;

// pisano period
int pisano(int M) {
	fibo.clear();
	fibo.push_back(0);
	fibo.push_back(1);
	
	int period;
	int i = 2;
	while (true) {
		int fi = fibo[i-2] + fibo[i-1];
		if (fi >= M)
			fi -= M;
		
		fibo.push_back(fi);
		if (fibo[i] == fibo[1] && fibo[i-1] == fibo[0]) {
			period = i - 1;
			break;
		}
		i++;
	}
	
	return period;
}

// BOJ #9471
void solve() {
	int n, m;
	cin >> n >> m;
	
	cout << n << ' ' << pisano(m) << '\n';
}

int fibo_pisano(ll n) {
	int period = pisano(MOD);
	int nn = n % period;
	return fibo[nn];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n;
	cin >> n;
	cout << fibo_power(n);
	
	return 0;
}


// Lucas's Theorem
// Binomial coefficients modulo prime

#include <iostream>
using namespace std;

int binomial[2001][2001];

void binom_coef(int M) {
	binomial[0][0] = 1;
		
    for (int i = 1; i <= M; i++) {
    	int* prev = binomial[i-1];
        int* next = binomial[i];
        
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
		return binomial[m][n];
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

int main(void) {
	long long N, K;
	int M;
	cin >> N >> K >> M;
	
	binom_coef(M);
	cout << lucas_thm(N, K, M);
}

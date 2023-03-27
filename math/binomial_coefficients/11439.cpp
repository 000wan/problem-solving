#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 4e6;

vector<int> primes;
bool sieve[MAX_N+1];
void init(int N) {
    for (int i = 2; i*i <= N; ++i) {
        if (sieve[i]) continue;
        for (int j = 2; i*j <= N; ++j) {
            sieve[i*j] = true;
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (!sieve[i])
            primes.emplace_back(i);
    }
}

int power(ll a, ll b, ll c) {
    ll res = 1;
    a = a%c;
    while (b > 0) {
        if (b&1) res = (res * a) % c;
        a = (a*a)%c;
        b >>= 1;
    }
    return res;
}

int binom_coeff(int N, int K, int M) {
    ll res = 1;
    for (auto& p : primes) {
        ll pk = p, sum = 0;
        while (N >= pk) {
            sum += N/pk - (N-K)/pk - K/pk;
            pk *= p;
        }
        res *= power(p, sum, M);
        res %= M;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, M;
    cin >> N >> K >> M;
    
    init(N);
    cout << binom_coeff(N, K, M) << '\n';

    return 0;
}

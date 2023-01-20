#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Harmonic Sum in O(sqrt(N)): [N/1]+[N/2]+...[N/N]
ll harmonic_sum(ll n) {
    ll res = 0;
    ll i, j;

    for (i = 1; i <= n; i = j+1) {
        j = n/(n/i); // max j s.t. [N/j] = [N/i]
        res += (n/i) * (j-i+1);
    }

    return res;
}

// Sum of Divisors
ll SOD(ll n) {
    // const int MOD = 1000000;
    ll res = 0;
    ll i, j;

    for (i = 1; i <= n; i = j+1) {
        j = n/(n/i); // max j s.t. [N/j] = [N/i]
        res += (n/i) * (((j-i+1) * (i+j)) / 2);
        // res %= MOD;
    }

    return res;
}

ll solve(int N) { // BOJ 15897
    ll res = 0;
    ll i, j;
    
    int n = N-1;
    for (i = 1; i <= n; i = j+1) {
        j = n/(n/i); 
        res += (1 + n/i) * (j-i+1);
    }
    res += 1;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    cin >> A >> B;

    cout << SOD(B) - SOD(A-1) << '\n';

    return 0;
}

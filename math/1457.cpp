#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Harmonic Sum in O(sqrt(N)): [N/1]+[N/2]+...[N/N]
ll harmonic_sum(ll n) {
    ll res = 0;
    ll i, j;

    for (i = 2; i <= n; i = j+1) {
        j = n/(n/i); // max j s.t. [N/j] = [N/i]
        res += (n/i - 1) * (j-i+1);
    }

    return res;
}

ll d(int S, int N) { 
    ll S1 = harmonic_sum(S);
    ll S2 = 0;

    for (int i = 2; pow(i, N) <= S; ++i) {
        S2 += S / pow(i,N);
    }

    return S1 - S2;
}

int solve(int A, int B, int N) {
    return d(A+B, N) - d(A-1, N);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, N;
    cin >> A >> B >> N;

    cout << solve(A, B, N) << '\n';

    return 0;
}

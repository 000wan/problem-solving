#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Harmonic Sum in O(sqrt(N)): [N/1]+[N/2]+...[N/N]
ll harmonic_sum(ll n) {
    ll res = 0;
    ll i, j;

    for (i = 1; i <= n; i = j+1) {
        j = n/(n/i); // max j s.t. [N/j] = [N/i]
        
        int s;
        if ((j-i+1)%2 == 0)
            s = 0;
        else if (i%2 == 0)
            s = 1;
        else
            s = -1;

        res += (n/i) * s;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll S, T;
    cin >> S >> T;

    cout << harmonic_sum(T) - harmonic_sum(S-1) << '\n';

    return 0;
}

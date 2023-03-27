#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 1e6;
bool sieve[MAX_N+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin >> n >> m;
    ll res = 0;
    for (ll i = 2; i*i <= m; ++i) {
        ll j = i*i;
        for (ll k = (n+j-1)/j; j*k <= m; ++k) {
            if (!sieve[j*k-n]) {
                sieve[j*k-n] = 1;
                res ++;
            }
        }
    }
    cout << m-n+1-res << '\n';

    return 0;
}

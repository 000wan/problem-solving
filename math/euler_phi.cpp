#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll euler_phi(ll n) {
    if (n == 1)
        return 1;

    for (ll i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            ll pk = 1;
            while (n % i == 0) {
                pk *= i;
                n /= i;
            }
            pk /= i;
            return pk * euler_phi(i) * euler_phi(n);
        }
    }

    return n-1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N;
    cin >> N;

    cout << euler_phi(N) << '\n';

    return 0;
}

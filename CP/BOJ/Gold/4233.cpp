#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int power(ll a, ll b, ll c) {
    a = a%c;
    ll res = 1;
    while (b>0) {
        if (b & 1)
            res = (res * a) % c;
        a = (a*a) % c;
        b = b>>1;
    }
    return res;
}

bool is_prime(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p, a;
    while (true) {
        cin >> p >> a;
        if (p == 0 && a == 0) return 0;
        if (power(a, p, p) == a && !is_prime(p))
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }

    return 0;
}

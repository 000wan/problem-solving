#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

ll sumf(ll A) {
    ll sum = 0;
    ll a = INF;
    for (int k = 0; a > 0; ++k) {
        ll q = A>>(k+1);
        ll r = (q<<(k+1))^A;
        a = (q<<k)+(r>>k)*((((r>>k)<<k)^r) + 1);
        sum += a;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll A, B;
    cin >> A >> B;
    
    cout << sumf(B) - sumf(A-1) << '\n';

    return 0;
}

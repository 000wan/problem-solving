#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

ll N, T;
ll a[200000];

bool check(int K) {
    if (K == 0) return false;

    int s[N];
    for (int i = 0; i < N; ++i) {
        if (i < K) {
            s[i] = max(a[i], T);
        } else {
            s[i] = max({a[i], T, s[i-K]+T});
            if (a[i] <= s[i]-T) return false;
        }
    }
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N >> T;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a+N);

    int lo = 0, hi = N, mid;
    while (lo+1 < hi) {
        mid = (lo+hi)/2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
    
    return 0;
}
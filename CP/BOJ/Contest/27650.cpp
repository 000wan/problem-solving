#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

ll sum[(int)1e6+1];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sum[i+1] = a[i] + sum[i];
    }

    ll res = 0, s = sum[N];
    for (int x = 0; x < N; ++x) {
        ll s1 = sum[x+1];
        int i = upper_bound(sum+1, sum+N+1, s1+(s-s1)/2) - sum-1;
        i = max(x+1, i);
        int j = lower_bound(sum+1, sum+N+1, s-s1) - sum-1;
        //cout << x << ' ' << i << ' ' << j << '\n';
        res += max(0, j-i);
    }
    cout << res << '\n';

    return 0;
}

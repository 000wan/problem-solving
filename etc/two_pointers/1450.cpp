#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N = 30;
const int HALF_N = 1<<15;

int a[MAX_N];
ll x[HALF_N], y[HALF_N];

void init(int start, int n, ll* arr) {
    for (int i = 0; i < (1<<n); ++i) {
        ll s = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1<<j))
                s += a[start+j];
        }
        arr[i] = s;
    }
}

void solve(int N, int C) {
    int lenx = 1<<(N/2), leny = 1<<(N-N/2);
    init(0, N/2, x);
    init(N/2, N-N/2, y);
    sort(y, y+leny);
    
    ll cnt = 0;
    for (int i = 0; i < lenx; ++i) {
        ll c = upper_bound(y, y+leny, C-x[i]) - y;
        cnt += c;
    }
    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C;
    cin >> N >> C;
    
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    solve(N, C);

    return 0;
}

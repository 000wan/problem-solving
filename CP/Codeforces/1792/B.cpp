#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int a[4];
    for (int i = 0; i < 4; ++i)
        cin >> a[i];
    
    int res = a[0];
    int cur[3] = {0, a[0], a[0]};
    int l = 1, r = 2;

    if (a[0] > 0 && (a[1] != 0 || a[2] != 0)) {
        int c = min(a[l], a[r]);
        res += 2*c;
        a[l] -= c;
        a[r] -= c;
        
        if (a[l] != a[r]) {
            if (a[l] < a[r])
                swap(l, r);

            int c = min(cur[r], a[l]);

            cur[l] += c;
            cur[r] -= c;
            a[l] -= c;
            res += c;    
        }
    }

    int d = min(a[3], min(cur[1], cur[2]));
    res += d;
    a[3] -= d;
    if (a[1] + a[2] + a[3] > 0)
        res++;

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }

    return 0;
}

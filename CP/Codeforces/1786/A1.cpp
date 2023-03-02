#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    pair<ll,ll> a = {0,0}, b = {0,0};
    auto& [ax, ay] = a;
    auto& [bx, by] = b;

    ll s1 = 0, s2 = 0;
    for (int i = 1; s1+s2 < n; ++i) {
        if (i%4 == 1 || i%4 == 0) {
            s1 += i;
            if (s1+s2 > n) {
                for (int j = 1; s1+s2-i+j <= n; ++j) {
                    if (j%2) ax += 1;
                    else ay += 1;
                }
                s1 = s1-(s1+s2-n);
            }
            else
                ax += i-i/2, ay += i/2;
        }
        else {
            s2 += i;
            if (s1+s2 > n) {
                for (int j = 1; s1+s2-i+j <= n; ++j) {
                    if (j%2) by += 1;
                    else bx += 1;
                }
                s2 = s2-(s1+s2-n);
            }
            else
                by += i-i/2, bx += i/2;
        }
    }
    cout << ax << ' ' << ay << ' ' << bx << ' ' << by << '\n';
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

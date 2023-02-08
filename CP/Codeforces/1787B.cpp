#include <bits/stdc++.h>
#define ll long long
using namespace std;

pair<int, int> ap[110];
int a[110];

void solve() {
    int N;
    cin >> N;
    
    int l = 1;
    for (int i = 2; i*i <= N; i++) {
        if (N%i == 0) {
            ap[l] = make_pair(0, i);
            while (N%i == 0) {
                ap[l].first += 1;
                N /= i;
            }
            l++;
        }
    }
    if (N != 1)
        ap[l++] = make_pair(1, N);
    l--;
    sort(ap+1, ap+l+1);

    a[l+1] = 1;
    for (int i = l; i >= 1; --i) {
        a[i] = a[i+1]*ap[i].second;
    }

    int res = 0;
    for (int i = 1; i <= l; ++i) {
        res += a[i]*(ap[i].first-ap[i-1].first);
    }
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

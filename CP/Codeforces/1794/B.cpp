#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < N-1; ++i) {
        if (a[i] == 1) {
            if (i > 0 && a[i-1] == 2) {
                a[i] = 3;
            }
            else {
                a[i] = 2;
            }
        }
        if (a[i+1]%a[i] == 0) {
            a[i+1] ++;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " \n"[i == N-1];
    }
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

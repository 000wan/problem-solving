#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    sort(a, a+N);
    
    int i = 0;
    int cnt = 0;
    while (a[N-1] != 0) {
        if (a[i] == 0) {
            i++;
            continue;
        }

        if (a[i] == 1 && i+1 < N) {
            a[i]--;
            a[i+1]--;
        }
        else {
            a[i++] = 0;
        }
        cnt ++;
    }

    cout << cnt << '\n';
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

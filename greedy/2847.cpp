#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int res = 0;
    for (int i = N-2; i >= 0; --i) {
        if (a[i] >= a[i+1]) {
            res += a[i] - a[i+1] + 1;
            a[i] = a[i+1] - 1;
        }
    }
    cout << res << '\n';

    return 0;
}

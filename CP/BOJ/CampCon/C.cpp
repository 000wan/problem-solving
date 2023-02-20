#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;
    int a[N];
    int sum = 0;
    int res = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sum += a[i];
        if (i-L >= 0)
            sum -= a[i-L];
        if (129 <= sum && sum <= 138)
            res ++;
    }
    cout << res << '\n';

    return 0;
}

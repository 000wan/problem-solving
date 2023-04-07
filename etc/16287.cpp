#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int W, N;
    cin >> W >> N;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    const int MAX_A = 4e5;
    bool dp[MAX_A+1] = {}, res = false;
    for (int i = 0; i+1 < N; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[a[i]+a[j]] = 1;
        }

        for (int j = i+2; j < N; ++j) {
            int d = W-(a[i+1]+a[j]);
            if (0 <= d && d <= MAX_A && dp[d]) {
                res = true;
            }
        }
    }
    cout << (res ? "YES" : "NO") << '\n';

    return 0;
}
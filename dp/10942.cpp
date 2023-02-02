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
    
    bool dp[2000][2000] = {};
    for (int l = 0; l < N; ++l) {
        for (int i = 0; i < N-l; ++i) {
            dp[i][i+l] = (a[i] == a[i+l]);
            if (i+1 <= i+l-1)
                dp[i][i+l] = dp[i][i+l] && dp[i+1][i+l-1];
        }
    }

    int M;
    cin >> M;
    
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        cout << (int)dp[x-1][y-1] << '\n';
    }

    return 0;
}

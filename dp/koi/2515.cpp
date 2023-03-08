#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 3e5;
int dp[MAX_N+1][2];

int main()
{
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;
    vector<pair<int,int>> a(N);
    for (auto& [h,c]: a)
        cin >> h >> c;
    sort(a.begin(), a.end());
    vector<int> H;
    for (auto& [h,c]: a)
        H.push_back(h);
    
    dp[0][0] = 0, dp[0][1] = a[0].second;
    for (int i = 1; i < N; ++i) {
        auto& [h, c] = a[i];
        int j = upper_bound(H.begin(), H.end(), h-S) - H.begin() - 1;
        if (j == i)
            dp[i][1] = c;
        else
            dp[i][1] = max(dp[j][0], dp[j][1])+c;
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
    }

    cout << max(dp[N-1][0], dp[N-1][1]) << '\n';


    return 0;
}

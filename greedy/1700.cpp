#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int late[101][101];
int cache[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    int a[K];
    for (int i = 0; i < K; ++i) {
        cin >> a[i];
    }
    fill(&cache[1], &cache[K+1], INF);
    for (int i = K-1; i >= 0; --i) {
        for (int k = 1; k <= K; ++k) {
            late[i][k] = cache[k];
        }
        cache[a[i]] = i;
    }

    vector<int> set;
    int res = 0;
    for (int i = 0; i < K; ++i) {
        if (find(set.begin(), set.end(), a[i]) != set.end())
            continue;
        if (set.size() < N) {
            set.push_back(a[i]);
            continue;
        }

        int m = -1;
        auto p = set.begin();
        for (auto it = set.begin(); it != set.end(); ++it) {
            int x = *it;
            if (late[i][x] > m)
                m = late[i][x], p = it;
        }
        res ++;
        set.erase(p);
        set.push_back(a[i]);
    }
    cout << res << '\n';

    return 0;
}

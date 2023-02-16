#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;


void solve() {
    int N, M;
    cin >> N >> M;

    char a[N+2][M+2] = {};
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> a[i][j];
        }
    }
    string pkey;
    cin >> pkey;

    queue<pair<int,int>> q;
    bool visited[N+2][M+2] = {};
    queue<pair<int,int>> doors[26];
    bool keys[26] = {};

    q.emplace(0, 0);
    visited[0][0] = true;
    if (pkey != "0") {
        for (auto& s : pkey) {
            keys[s-'a'] = true;
        }
    }
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int res = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (a[x][y] == '$')
            res ++;
        if (a[x][y] >= 'a' && a[x][y] <= 'z') {
            keys[a[x][y]-'a'] = true;
            queue<pair<int,int>>& door = doors[a[x][y]-'a'];
            while (!door.empty()) {
                q.emplace(door.front());
                door.pop();
            }
        }
        
        for (int i = 0; i < 4; ++i) {
            int sx = x+dx[i], sy = y+dy[i];
            if (sx < 0 || sx > N+1) continue;
            if (sy < 0 || sy > M+1) continue;
            if (visited[sx][sy]) continue;
            if (a[sx][sy] == '*') continue;
            
            if (a[sx][sy] >= 'A' && a[sx][sy] <= 'Z' && !keys[a[sx][sy]-'A']) {
                doors[a[sx][sy]-'A'].emplace(sx, sy);
            }
            else {
                q.emplace(sx, sy);
            }
            visited[sx][sy] = true;
        }
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

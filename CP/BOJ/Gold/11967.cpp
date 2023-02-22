#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int,int>> next[N+1][N+1];
    for (int i = 0; i < M; ++i) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        next[x][y].emplace_back(a, b);
    }

    int res = 1;

    bool visited[N+1][N+1] = {};
    bool able[N+1][N+1] = {};
    bool p[N+1][N+1] = {};
    std::queue<pair<int,int>> q;

    q.emplace(1,1);
    visited[1][1] = true, able[1][1] = true;
    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();

        for (auto& [lx,ly] : next[x][y]) {
            if (!able[lx][ly])
                able[lx][ly] = true, res++;
            if (p[lx][ly]) {
                q.emplace(lx,ly);
                p[lx][ly] = false;
            }
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 1 || nx > N || ny < 1 || ny > N)
                continue;
            if (visited[nx][ny]) continue;

            if (able[nx][ny])
                q.emplace(nx,ny);
            else
                p[nx][ny] = true;
            visited[nx][ny] = true;
        }
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

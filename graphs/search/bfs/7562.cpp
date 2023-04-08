#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};

const int MAX_N = 300;
int N, visited[MAX_N][MAX_N];
void bfs(pii start, pii end) {
    auto [sx, sy] = start;
    auto [ex, ey] = end;
    
    queue<pii> q; queue<int> cnt;
    q.push(start); cnt.push(0);
    visited[sx][sy] = 1;
    
    while (!q.empty()) {
        pii v = q.front(); q.pop();
        int c = cnt.front(); cnt.pop();
        if (v == end) {
            cout << c << '\n';
            return;
        }

        auto [x, y] = v;
        for (int i = 0; i < 8; ++i) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (visited[nx][ny]) continue;
            
            q.emplace(nx, ny); cnt.push(c+1);
            visited[nx][ny] = 1;
        }
    }
}

void solve() {
    cin >> N;
    fill(&visited[0][0], &visited[N-1][N], 0);
    pii start, end;
    auto& [sx, sy] = start;
    cin >> sx >> sy;
    auto& [ex, ey] = end;
    cin >> ex >> ey;
    
    bfs(start, end);
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
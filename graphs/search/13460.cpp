#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char a[10][10];
pair<pair<int,int>, int> mv(int x, int y, int i) {
    int dist = 0;
	while (a[x+dx[i]][y+dy[i]] != '#' && a[x][y] != 'O')
	{
		x += dx[i];
		y += dy[i];
        dist ++;
	}

    return make_pair(make_pair(x, y), dist);
}

bool visited[10][10][10][10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    queue<pair<int,int>> red, blue;
    pair<int,int> dest;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'R') {
                red.emplace(i, j);
            }
            if (a[i][j] == 'B') {
                blue.emplace(i, j);
            }
            if (a[i][j] == 'O') {
                dest = make_pair(i, j);
            }
        }
    }
    
    int res = INF;
    queue<int> cnt;
    cnt.emplace(0);
    while (!red.empty()) {
        auto r = red.front(), b = blue.front();
        auto c = cnt.front();
        auto [rx, ry] = r;
        auto [bx, by] = b;
        red.pop(), blue.pop(), cnt.pop();

        if (!visited[rx][ry][bx][by])
            visited[rx][ry][bx][by] = true;

        if (b == dest) {
            continue;
        }
        if (r == dest) {
            res = min(res, c);
            break;
        }
        
        if (c == 10)
            continue;

        for (int i = 0; i < 4; ++i) {
            auto [nr, rdist] = mv(rx, ry, i);
            auto [nb, bdist] = mv(bx, by, i);
            auto [nrx, nry] = nr;
            auto [nbx, nby] = nb;
            
            if (nr == nb && nr != dest) {
                if (rdist > bdist) nrx -= dx[i], nry -= dy[i];
                else nbx -= dx[i], nby -= dy[i];
            }
            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                red.emplace(nrx, nry);
                blue.emplace(nbx, nby);
                cnt.emplace(c+1);
            }
        }
    }

    if (res == INF)
        cout << -1 << '\n';
    else
        cout << res << '\n';

    return 0;
}

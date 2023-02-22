#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char a[11][11];
int resn, resc;
void search(int n, int cnt) {
    if (n < resn) {
        resn = n;
        resc = cnt;
    }
    else if (n == resn)
        resc = min(resc, cnt);

    for (int x = 1; x <= 5; ++x) {
        for (int y = 1; y <= 9; ++y) {
            if (a[x][y] != 'o') continue;
            for (int i = 0; i < 4; ++i) {
                int nx = x+dx[i], ny = y+dy[i];
                int nnx = nx+dx[i], nny = ny+dy[i];
                if (nnx < 0 || nnx > 5 || nny < 0 || nny > 9)
                    continue;

                if (a[nx][ny] == 'o' && a[nnx][nny] == '.') {
                    a[x][y] = a[nx][ny] = '.', a[nnx][nny] = 'o';
                    search(n-1, cnt+1);
                    a[x][y] = a[nx][ny] = 'o', a[nnx][nny] = '.';
                }
            } 

        }
    }
}

void solve() {
    resn = resc = INF;
    int n = 0;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'o') n++;
        }
    }

    search(n, 0);
    cout << resn << ' ' << resc << '\n';
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

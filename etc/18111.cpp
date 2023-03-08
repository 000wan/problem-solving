#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int a[500][500];
int N, M, B;

int solve(int h) {
    int block = 0, time = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (a[i][j] > h) {
                block -= a[i][j] - h;
                time += 2*(a[i][j] - h);
            }
            else if (a[i][j] < h) {
                block += h - a[i][j];
                time += h - a[i][j];
            }
        }
    }

    if (block > B)
        return INF;
    return time;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> B;
    for (int i = 0; i < N*M; ++i) {
        cin >> a[i/M][i%M];
    }

    int time = INF, height = 0;
    for (int h = 0; h <= 256; ++h) {
        int ntime = solve(h);
        if (ntime <= time) {
            time = ntime;
            height = h;
        }
    }

    printf("%d %d", time, height);

    return 0;
}

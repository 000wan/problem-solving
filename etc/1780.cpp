#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 2187;
int a[MAX_N+1][MAX_N+1];

vector<int> comp(int x0, int x1, int y0, int y1) {
    if (x0 == x1 && y0 == y1) {
        vector<int> res(3, 0);
        res[1+a[x0][y0]] ++;
        return res;
    }
    int dx = (x1-x0+1)/3, dy = (y1-y0+1)/3;
    vector<int> s[9];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int nx = x0+i*dx, ny = y0+j*dy;
            s[3*i+j] = comp(nx, nx+dx-1, ny, ny+dy-1);
        }
    }

    vector<int> res(3, 0);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 3; ++j) {
            res[j] += s[i][j];
        }
    }
    int sum = res[0]+res[1]+res[2];
    for (int i = 0; i < 3; ++i) {
        if (res[i] == 9 && sum == 9) {
            res[i] = 1;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N*N; ++i) {
        cin >> a[i/N+1][i%N+1];
    }
    vector<int> res = comp(1, N, 1, N);
    for (auto& i : res) {
        cout << i << '\n';
    }

    return 0;
}


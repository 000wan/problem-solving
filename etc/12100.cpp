#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
vector<vector<int>> a;

int res = 0;
void search(int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (a[i][j] > res) res = a[i][j];
            }
        }
        return;
    }
    vector<vector<int>> b;
    b = a;
    
    int I, J, l, r, m, x, y;
    for (int d = 0; d < 4; ++d) {
        a = b;

        for (int i = 0; i < N; ++i) {
            int k = 0;
            for (int j = 0; j < N; ++j) {
                I = (d<2) ? i : N-1-i;
                J = (d<2) ? j : N-1-j;
                l = (d%2) ? J : I;
                r = (d%2) ? I : J;
                m = (d<2) ? k : N-1-k;

                if (a[l][r] > 0 && J != m) {
                    x = (d%2) ? m : l;
                    y = (d%2) ? r : m;

                    if (a[x][y] == 0) {
                        a[x][y] = a[l][r];
                        a[l][r] = 0;
                    }
                    else if (a[x][y] == a[l][r]) {
                        a[x][y] += a[l][r];
                        a[l][r] = 0;
                        k++;
                    }
                    else {
                        k++;
                        m = (d<2) ? k : N-1-k;
                        x = (d%2) ? m : l;
                        y = (d%2) ? r : m;
                        a[x][y] = a[l][r];
                        if (J != m) a[l][r] = 0;
                    }
                }
            }
        }
        search(cnt + 1);   
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    a = vector<vector<int>>(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }

    search(0);
    cout << res << '\n';

    return 0;
}


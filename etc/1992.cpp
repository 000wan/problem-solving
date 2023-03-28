#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

char a[64][64];

string comp(int x0, int x1, int y0, int y1) {
    if (x0 == x1 && y0 == y1) {
        string res(1, a[x0][y0]);
        return res;
    }
    int xm = (x0+x1)/2, ym = (y0+y1)/2;
    string s[4];
    s[0] = comp(x0, xm, y0, ym);
    s[1] = comp(x0, xm, ym+1, y1);
    s[2] = comp(xm+1, x1, y0, ym);
    s[3] = comp(xm+1, x1, ym+1, y1);

    string res;
    for (int i = 0; i < 4; ++i) {
        if (s[i].size() == 1)
            res += s[i];
        else
            res += "("+s[i]+")";
    }
    if (res.size() == 4) {
        if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3])
            res = s[0];
    }
    return res;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N*N; ++i) {
        cin >> a[i/N][i%N];
    }
    string res = comp(0, N-1, 0, N-1);
    if (res.size() > 1) res = "("+res+")";
    cout << res << '\n';

    return 0;
}

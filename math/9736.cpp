#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define pii pair<int,int>

pii ba2ab(int q, int p) {
    return {(q&1 ? -1 : 1) * p, q};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int n, m, t;

    while (true) {
        cin >> s >> n >> m >> t;
        if (!n && !m && !t) break;
        char a,b;
        int j, k, p, q;
        while (t--) {
            cin >> a >> j >> b >> k;
            cin >> a >> p >> b >> q;
            auto [mx, my] = ba2ab(k, p);
            int x = j+mx, y = q+my;
            x = (x%n+n)%n, y = (y%m+m)%m;
            printf("ProblemID %s: a%db%d * a%db%d = a%db%d\n", s.c_str(), j, k, p, q, x, y);
        }
    }


    return 0;
}

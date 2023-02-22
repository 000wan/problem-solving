#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int mxX = 5e5;
#define hash(x) (x+mxX)
int cntx[2*mxX+1], cnty[2*mxX+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<pair<int,int>> hor, ver;
    pair<int,int> first, prev, curr;

    auto& [fx, fy] = first;
    cin >> fx >> fy;
    prev = first;

    auto& [x, y] = curr;
    auto& [px, py] = prev;
    for (int i = 1; i <= N; ++i) {
        if (i < N) cin >> x >> y;
        else curr = first;

        if (x == px) {
            ver.emplace_back(min(y,py), max(y,py));
        } else if (y == py) {
            hor.emplace_back(min(x,px), max(x,px));
        }
        prev = curr;
    }

    for (auto& [x1, x2] : hor) {
        cntx[hash(x1)]++, cntx[hash(x2)]--;
    }
    for (auto& [y1, y2] : ver) {
        cnty[hash(y1)]++, cnty[hash(y2)]--;
    }

    int res = 0;
    for (int i = 1; i <= 2*mxX; ++i) {
        cntx[i] += cntx[i-1];
        cnty[i] += cnty[i-1];
        res = max(res, max(cntx[i], cnty[i]));
    }
    cout << res << '\n';

    return 0;
}

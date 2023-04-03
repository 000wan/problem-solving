#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define tii tuple<int,int,int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, C, M;
    cin >> N >> C >> M;
    
    vector<tii> a;
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a.emplace_back(v, u, w);
    }
    sort(a.begin(), a.end());
    
    int res = 0;
    int W[N+1] = {};
    for (auto& [v, u, w] : a) {
        int mw = 0;
        for (int i = u; i < v; ++i) {
            mw = max(mw, W[i]);
        }
        int dw = max(0, min(w, C-mw));
        for (int i = u; i < v; ++i) {
            W[i] += dw;
        }
        res += dw;
    }
    cout << res << '\n';

    return 0;
}
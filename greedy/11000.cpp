#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

#define pii pair<int,int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pii> a(N);
    for (auto& [s, e]: a)
        cin >> s >> e;
    sort(a.begin(), a.end());

    std::priority_queue<pii, vector<pii>, greater<>> ends;
    int res = 0;
    for (auto& [s, e]: a) {
        auto& [te, ts] = ends.top();
        if (ends.empty() || s < te) {
            res ++;
        } else {
            ends.pop();
        }
        ends.emplace(e, s);
    }
    cout << res << '\n';

    return 0;
}

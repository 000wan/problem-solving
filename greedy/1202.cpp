#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

struct Node {
    int m, v;
};
bool cmp(const Node& v1, const Node& v2) {
    if (v1.m == v2.m) {
        return v1.v < v2.v;
    }
    return v1.m < v2.m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    
    std::vector<Node> a;
    for (int i = 0; i < N; ++i) {
        int m, v;
        cin >> m >> v;
        a.push_back({m, v});
    }
    sort(a.begin(), a.end(), cmp);

    int c[K];
    for (int i = 0; i < K; ++i) {
        cin >> c[i];
    }
    sort(c, c+K);
    
    ll res = 0;
    int i, j = 0; // i for bag, j for Nodes
    std::priority_queue<int> pq;
    for (i = 0; i < K; i++) {
        while (j < N && a[j].m <= c[i])
            pq.push(a[j++].v);
        if (pq.empty())
            continue;
        res += pq.top();
        pq.pop();
    }

    cout << res << '\n';

    return 0;
}

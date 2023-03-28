#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 1e3;
struct Edge{
    int to, cnt;
    Edge* back;
    Edge(int to, int cnt): to(to), cnt(cnt){}
};

int N, deg[MAX_N+1];
vector<Edge*> adj[MAX_N+1];
// Hierholzer's Algorithm: find euler circuit by DFS
void euler_circuit(int curr, vector<int>& res) {
    while (!adj[curr].empty()) {
        auto e = adj[curr].back();
        if (e->cnt > 0) {
            e->cnt -= 1;
            e->back->cnt -= 1;
            euler_circuit(e->to, res);
        } else {
            adj[curr].pop_back();
        }
    }
    res.push_back(curr);
}

// all verticies should have even degree
bool check_euler_circuit() {
    for (int i = 1; i <= N; ++i) {
        if (deg[i]%2 == 1) return false;
    }
    return true;
}

vector<int> get_euler_circuit(int start) {
    vector<int> res;
    euler_circuit(start, res);
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int val;
            cin >> val;
            if (val && j > i) {
                Edge *e1 = new Edge(j, val), *e2 = new Edge(i, val);
                e1->back = e2, e2->back = e1;
                adj[i].push_back(e1), adj[j].push_back(e2);
                deg[i] += val, deg[j] += val;
            }
        }
    }

    if (!check_euler_circuit()) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> res = get_euler_circuit(1);
    for (auto& i : res) {
        cout << i << ' ';
    }

    return 0;
}

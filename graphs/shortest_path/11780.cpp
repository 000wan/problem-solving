#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

// floyd-warshall: o(v^3), find all path pairs, available for negative weights
void floyd(int V, vector<pair<int, int>> adj[]) {
    vector<vector<ll>> d(V+1, vector<ll> (V+1, INF));
    vector<vector<int>> prev(V+1, vector<int>(V+1, -1));

    for (int v = 1; v <= V; ++v) {
        d[v][v] = 0;
        for (auto iter = adj[v].begin(); iter != adj[v].end(); ++iter) {
            int w = iter->first;
            int weight = iter->second;
            d[v][w] = min(d[v][w], (ll)weight);
            if (d[v][w] == weight)
                prev[v][w] = v;
        }
    }

    for (int m = 1; m <= V; m++) { // middle node
        for (int v = 1; v <= V; v++) {
            for (int w = 1; w <= V; w++) {
                if (d[v][w] > d[v][m] + d[m][w]) {
                    d[v][w] = d[v][m] + d[m][w];
                    prev[v][w] = prev[m][w];
                }
            }
        }
    }
    
    // cost
    for (int v = 1; v <= V; v++) {
        for (int w = 1; w <= V; w++) {
            if (d[v][w] == INF)
                cout << 0 << ' ';
            else
                cout << d[v][w] << ' ';
        }
        cout << '\n';
    }
    // path
    for (int v = 1; v <= V; v++) {
        for (int w = 1; w <= V; w++) { 
            if (d[v][w] == INF || v == w) {
                cout << 0 << '\n';
                continue;
            }

            stack<int> path;
            path.emplace(w);
            int i = w;
            while (prev[v][i] != -1) {
                path.emplace(prev[v][i]);
                i = prev[v][i];
            }

            cout << path.size() << ' ';
            while (!path.empty()) {
                cout << path.top() << ' ';
                path.pop();
            }
            cout << '\n';
        }
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int V, E;
	cin >> V >> E;
	
	vector<pair<int, int>> adj[V+1]; // first: vertex, second: weight
	
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
    
    // floyd-warshall
    floyd(V, adj);

    return 0;
}

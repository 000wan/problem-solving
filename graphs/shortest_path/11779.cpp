#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

// Dijkstra: O(VlogE), only for positive weights
void dijkstra(int s, int e, int V, vector<pair<int, int>> adj[]) {
    vector<int> D(V+1, INF);
	D[s] = 0;
	
	priority_queue<pair<int, int>> pq; // first: -distance, second: vertex
	pq.push(make_pair(0, s));
	
    vector<int> prev(V+1, -1);
	while(!pq.empty()) {
		// Find min vertex
		int dist = -pq.top().first;
		int v = pq.top().second;
		pq.pop();
		
		if (D[v] < dist) // not the latest
			continue;
		
		// Edge relaxation
		for (auto& [w, weight] : adj[v]) {
			if (D[v] + weight < D[w]) { // update
				D[w] = D[v] + weight;
                prev[w] = v;
				pq.push(make_pair(-D[w], w));
			}
		}
	}
	cout << D[e] << '\n';
    
    stack<int> path;
    path.emplace(e);
    int v = e;
    while (prev[v] != -1) {
        path.emplace(prev[v]);
        v = prev[v];
    }

    cout << path.size() << '\n';
    while (!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }
}

int main() {
	int V, E;
	cin >> V >> E;
	
	vector<pair<int, int>> adj[V+1]; // first: vertex, second: weight
	
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}

    int v1, v2;
    cin >> v1 >> v2;
	
    // dijkstra
	dijkstra(v1, v2, V, adj);
}

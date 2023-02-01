#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define INF (int)1e9

int dijkstra(int s, int dest, int V, vector<pair<int, int>> adj[]) {
	int* D = new int[V+1];
	
	for (int i = 0; i <= V; ++i)
		D[i] = INF;
	D[s] = 0;
	
	priority_queue<pair<int, int>> pq; // first: -distance, second: vertex
	pq.push(make_pair(0, s));
	
	while(!pq.empty()) {
		// Find min vertex
		int dist = -pq.top().first;
		int v = pq.top().second;
		pq.pop();
		
		if (D[v] < dist) // not the latest
			continue;
		
		// Edge relaxation
		for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
			int w = it->first;
			int weight = it->second;
			
			if (D[v] + weight < D[w]) { // update
				D[w] = D[v] + weight;
				pq.push(make_pair(-D[w], w));
			}
		}
	}
	
	return D[dest];
}

void solve() {
	int V, E, t;
	cin >> V >> E >> t;
	
	int s, g, h;
	cin >> s >> g >> h;
	
	vector<pair<int, int>> adj[V+1]; // first: vertex, second: weight
	int gh;
	
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if ((u == g && v == h) || (v == g && u == h)) {
			gh = w;
		}
			
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	
	int sg = dijkstra(s, g, V, adj);
	int sh = dijkstra(s, h, V, adj);
	
	vector<int> res;
	for (int i = 0; i < t; i++) {
		int x;
		cin >> x;
		
		int sx = dijkstra(s, x, V, adj);
		int hx = dijkstra(h, x, V, adj);
		int gx = dijkstra(g, x, V, adj);
		
		if (sg != INF && hx != INF && sg+gh+hx == sx)
			res.push_back(x);
		else if (sh != INF && gx != INF && sh+gh+gx == sx)
			res.push_back(x);
	}
	
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << ' ';
	cout << '\n';
	
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	
	while (T--)
		solve();
	
	return 0;
}


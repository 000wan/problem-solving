#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 1000;
vector<pair<int, int>> adj[MAX_N+1];

// Dijkstra: O(VlogE), only for positive weights
vector<int> dijkstra(int s, int V, int K) {
    priority_queue<int> D[V+1];
	D[s].push(0);
	
	priority_queue<pair<int, int>> pq; // first: -distance, second: vertex
	pq.emplace(0, s);
	
	while(!pq.empty()) {
		// Find min vertex
		int dist = -pq.top().first;
		int v = pq.top().second;
		pq.pop();
		
		// Edge relaxation
		for (auto& [w, weight] : adj[v]) {
            int ndist = dist + weight;
            if ((int)D[w].size() < K) {
                D[w].push(ndist);
                pq.emplace(-ndist, w);
            }
            else if (ndist < D[w].top()) {
                D[w].pop();
                D[w].push(ndist);
                pq.emplace(-ndist, w);
			}
		}
	}

    vector<int> ret(V+1);
    for (int v = 1; v <= V; ++v) {
        ret[v] = (D[v].size() == K) ? D[v].top() : INF;
    }
	return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
    // dijkstra
	vector<int> D = dijkstra(1, N, K);
	for (int v = 1; v <= N; v++) {
		if (D[v] == INF)
			cout << -1 << '\n';
		else
			cout << D[v] << '\n';
	}
    
    return 0;
}
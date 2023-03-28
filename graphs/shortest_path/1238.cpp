#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

#define pii pair<int,int>
const int MAX_N = 1e3;

vector<pii> adj[MAX_N+1];
// Dijkstra: O(VlogE), only for positive weights
vector<int> dijkstra(int s, int V) {
    vector<int> D(V+1, INF);
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
	
	return D;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, x;
    cin >> N >> M >> x;
    for (int i = 0, u, v, w; i < M; ++i) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    vector<int> D[N+1];
    for (int v = 1; v <= N; ++v) {
        D[v] = dijkstra(v, N);
    }
    int res = 0;
    for (int v = 1; v <= N; ++v) {
        res = max(res, D[v][x] + D[x][v]);
    }
    cout << res << '\n';

    return 0;
}

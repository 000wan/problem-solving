#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define pii pair<int,int>

// Dijkstra: O(VlogE), only for positive weights
vector<int> dijkstra(int s, int V, vector<vector<int>> adj) {
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
        for (int w = 1; w <= V; ++w) {
			int weight = adj[v][w];
            if (!weight) continue;
			
			if (D[v] + weight < D[w]) { // update
				D[w] = D[v] + weight;
				pq.push(make_pair(-D[w], w));
			}
		}
	}
	
	return D;
}

bool solve() {
    int V, E;
    cin >> V >> E;
    if (!V && !E) return false;

    int s, e;
    cin >> s >> e;
    s++, e++;

    vector<vector<int>> adj(V+1, vector<int>(V+1, 0));
    for (int i = 0, u, v, w; i < E; ++i) {
        cin >> u >> v >> w;
        u++, v++;
        adj[u][v] = w;
    }

    auto Di = dijkstra(s, V, adj);
    queue<int> Q;
    Q.push(e);
    while (!Q.empty()) {
        int curr = Q.front(); Q.pop();
        for (int next = 1; next <= V; ++next) {
            if (curr == next) continue;
            if (!adj[next][curr]) continue;
            if (Di[curr] == Di[next] + adj[next][curr]) {
                Q.push(next);
                adj[next][curr] = 0;
            }
        }
    }

    auto D2 = dijkstra(s, V, adj);
    if (D2[e] == INF)
        cout << -1 << '\n';
    else
        cout << D2[e] << '\n';
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        if (!solve())
            break;
    }   

    return 0;
}

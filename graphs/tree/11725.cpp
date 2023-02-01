#include <bits/stdc++.h>
#define ll long long

#define MAX_N 100000

std::vector<int> adj[MAX_N+1];
int prev[MAX_N+1];

void DFS(int root, int parent) {
	for (auto c=adj[root].begin(); c!=adj[root].end(); c++) {
		if (*c == parent)
			continue;
		
		prev[*c] = root;
		DFS(*c, root);
	}
	
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int N;
	std::cin >> N;
	
	for (int i=0; i<N-1; i++) {
		int u, v;
		std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	DFS(1, 0);
	
	for (int i=2; i<=N; i++)
		std::cout << prev[i] << '\n';
	
	return 0;
}


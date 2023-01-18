#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAX_N 100000
#define None 0

vector<pair<int, int>> child[MAX_N+1];
int diameter = 0;

int depth(int root, int parent) {
	int max1 = 0;
	int max2 = 0;
	
	for (auto c=child[root].begin(); c!=child[root].end(); c++) {
		if (c->first == parent)
			continue;
		
		int d = depth(c->first, root) + c->second;
		
		if (d > max1) {
			max2 = max1;
			max1 = d;
		}
		else if (d > max2) {
			max2 = d;
		}
	}
	
	diameter = max(diameter, max1+max2);
	return max1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	int u;
	for (int i=0; i<N; ++i) {
		cin >> u;
		
		while (true) {
			int v, w;
			cin >> v;
			
			if (v == -1)
				break;
			cin >> w;
			
			child[u].push_back(make_pair(v, w));
		}
	}
	
	int root = u;
	depth(root, None);
	cout << diameter;
	
	return 0;
}


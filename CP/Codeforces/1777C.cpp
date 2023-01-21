// Not Completed

#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAX_N (int)1e5
#define MAX_M (int)1e5
#define INF (int)1e5

vector<int> divisor[MAX_N+1];

void init() {
	for (int i=1; i<=MAX_M; ++i) {
		for (int j=1; i*j<=MAX_N; ++j) {
			divisor[i*j].push_back(i);
		}	
	}
}

int search(int i, int n, int m, bool visited[], int first, int last, int a[]) {
	if (i == n) {
		bool flag=true;
		for (int j=1; j<=m; ++j)
			flag = flag && visited[j];
			
		if (flag)
			return a[last]-a[first];
		return INF;
	}
	
	int res;
	int nfirst = first;
	if (first == -1)
		nfirst = i;
	
	for (auto it=divisor[a[i]].begin(); it!=divisor[a[i]].end(); it++) {
		if (1 <= *it && *it <= m)
			visited[*it] = true;
	}
	res = search(i+1, n, m, visited, nfirst, i, a);
	for (auto it=divisor[a[i]].begin(); it!=divisor[a[i]].end(); it++) {
		if (1 <= *it && *it <= m)
			visited[*it] = false;
	}
	
	res = min(res, search(i+1, n, m, visited, first, last, a));
	
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	
	bool visited[m+1] = {};
	int res = search(0, n, m, visited, -1, INF, a);
	if (res == INF)
		res = -1;
	
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	init();
	
	int t;
	cin >> t;
	while(t--)
		solve();
	
	return 0;
}


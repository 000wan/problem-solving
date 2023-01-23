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

void solve() {
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
    
    int res = INF;
    int l = 0;
    int r = -1;
    std::unordered_map<int, int> visited;
    while (r < n-1) {
        while ((int)visited.size() < m) {
            if (++r >= n) {
				r--;
				break;
			}
            for (auto i = divisor[a[r]].begin(); i != divisor[a[r]].end(); ++i) {
                if (1 <= *i && *i <= m)
                    visited[*i]++;
            }
        }
        
        while ((int)visited.size() == m) {
            res = min(res, a[r]-a[l]);
	        //cout << l << ' ' << r << ' ' << visited.size() <<'\n';
            
			for (auto i = divisor[a[l]].begin(); i != divisor[a[l]].end(); ++i) {
                if (1 <= *i && *i <= m)
                    if (--visited[*i] <= 0)
                    	visited.erase(*i);
            }
            if (++l >= n) {
            	l--;
				break;
            }
        }
    }
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


#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int N) {
	unordered_map<int,int> s;
	int cnt = 0;
	
	for(int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		
		if (b == 1) {
			if (s[a] == 1) {
				cnt++;
			}
			s[a] = 1;
		}
		else if (b == 0) {
			if (s[a] == 0) {
				cnt++;
			}
			s[a] = 0;
		}
	}
	
	unordered_map <int,int>::iterator it;
    for(it = s.begin(); it != s.end() ; it++) {
        cnt += it->second;
    }
	
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	cout << solve(N);	
	
	return 0;
}


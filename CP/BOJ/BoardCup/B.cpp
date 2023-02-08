#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	unordered_map<string, int> s;
	for (int i = 0; i < N; ++i) {
		string name;
		int x;
		cin >> name >> x;
		
		s[name] += x;
	}
	
	bool flag = false;
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (it->second == 5) {
			flag = true;
			break;
		}
	}
	
	if (flag)
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}


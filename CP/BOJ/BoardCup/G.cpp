#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	N++;
	
	int a[N];
	int cnt = 0;
	for (int i=0; i<N; ++i) {
		cin >> a[i];
		if (a[i] == 1)
			cnt++;
	}
	
	int x;
	cin >> x;
	
	if (cnt == 0) {
		bool flag = false;
		
		for (int i=0; i<N; ++i) {
			int j = i + x;
			if (j >= N)
				break;
			
			if (a[i] >= 3 && a[j] >= 2) {
				cout << "YES" << '\n';
				cout << i << ' ' << j;
				flag = true;
				break;
			}
		}
		
		if (!flag)
			cout << "NO";
	}
	else if (cnt == 1) {
		bool flag = false;
		
		for (int i=0; i<N; ++i) {
			int j = i + x;
			if (j >= N)
				break;
			
			if ((a[i] >= 3 && a[j] == 1) || (a[j] >= 3 && a[i] == 1)) {
				cout << "YES" << '\n';
				cout << i << ' ' << j;
				flag = true;
				break;
			}
		}
		
		if (!flag)
			cout << "NO";
	}
	else if (cnt == 2) {
		bool flag = false;
		
		for (int i=0; i<N; ++i) {
			int j = i + x;
			if (j >= N)
				break;
			
			if (a[i] == 1 && a[j] == 1) {
				cout << "YES" << '\n';
				cout << i << ' ' << j;
				flag = true;
				break;
			}
		}
		
		if (!flag)
			cout << "NO";
	}
	else {
		cout << "NO";
	}
	
	return 0;
}


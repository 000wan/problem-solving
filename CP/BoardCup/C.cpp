#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	int time = 1;
	int sign = 1;
	for (int i = 0; i < N; i++) {
		string name;
		int x;
		cin >> name >> x;
		
		cout << time << ' ';
		if (x == time && name == "HOURGLASS") {
			cout << "NO" << '\n';
		}
		else if (x == time) {
			cout << "YES" << '\n';
		}
		else if (name == "HOURGLASS") {
			cout << "NO" << '\n';
			sign *= -1;
		}
		else {
			cout << "NO" << '\n';
		}
		
		time += sign;
		if (time > 12) {
			time = (time - 1)%12 + 1;
		}
		if (time < 1) {
			time = (12 + (time - 1)%12)%12 + 1;
		}
	}
	
	return 0;
}


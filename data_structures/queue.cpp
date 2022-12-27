#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();
	
	queue<int> Q;
	for (int i = 0; i < N; i++) {
		string inp;
		getline(cin, inp);
		
		if (inp.substr(0, 4) == "push") {
			int x = stoi(inp.substr(5));
			Q.push(x);
		} else if (inp == "pop") {
			if (Q.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		} else if (inp == "size") {
			cout << Q.size() << '\n';
		} else if (inp == "empty") {
			cout << (int)Q.empty() << '\n';
		} else if (inp == "front")  {
			if (Q.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << Q.front() << '\n';
			}
		} else if (inp == "back") {
			if (Q.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << Q.back() << '\n';
			}
		}
	}

	return 0;
}

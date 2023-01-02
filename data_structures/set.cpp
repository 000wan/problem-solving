#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();
	
	set<int> all;
	for (int i = 1; i <= 20; ++i) {
		all.insert(i);
	}
	
	set<int> S;
	
	for (int i = 0; i < N; i++) {
		string inp;
		getline(cin, inp);
		
		if (inp.substr(0, 3) == "add") {
			int x = stoi(inp.substr(4));
			S.insert(x);
		}
		else if (inp.substr(0, 6) == "remove") {
			int x = stoi(inp.substr(7));
			S.erase(x);
		}
		else if (inp.substr(0, 5) == "check") {
			int x = stoi(inp.substr(6));
			cout << S.count(x) << '\n';
		}
		else if (inp.substr(0, 6) == "toggle") {
			int x = stoi(inp.substr(7));
			int t = S.erase(x);
			
			if (t == 0) {
				S.insert(x);
			} 
		}
		else if (inp == "all") {
			S.clear();
			S = all;
		}
		else if (inp == "empty") {
			S.clear();
		}
	}

	return 0;
}

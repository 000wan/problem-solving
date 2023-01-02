#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();
	
	// Set implement by BitMask
	int S = 0;
	
	for (int i = 0; i < N; i++) {
		string inp;
		getline(cin, inp);
		
		if (inp.substr(0, 3) == "add") {
			int x = stoi(inp.substr(4));
			S = S | (1 << x);
		}
		else if (inp.substr(0, 6) == "remove") {
			int x = stoi(inp.substr(7));
			S = S & ~(1 << x);
		}
		else if (inp.substr(0, 5) == "check") {
			int x = stoi(inp.substr(6));
			int check = (S >> x) & 1;
			cout << check << '\n';
		}
		else if (inp.substr(0, 6) == "toggle") {
			int x = stoi(inp.substr(7));
			S = S ^ (1 << x);
		}
		else if (inp == "all") {
			S = 0;
			S = (1 << 21) - 2;
			// S = (~0 >> 12) << 1;
		}
		else if (inp == "empty") {
			S = 0;
		}
	}

	return 0;
}

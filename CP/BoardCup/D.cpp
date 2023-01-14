#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(bool rule[], int a, int b, int c) {
	int M = 0;
	
	// 1 ~ 6
	for (int i = 1; i <= 6; i++) {
		if (rule[i]) {
			int res = i*(a == i) + i*(b == i) + i*(c == i) + 2*i;
			M = max(M, res);
		}
	}
	
	// 7: Four of a Kind
	if (rule[7]) {
		if (a == b || a == c) {
			int res = 4*a;
			M = max(M, res);
		}
		if (b == c) {
			int res = 4*b;
			M = max(M, res);
		}
	}
	
	// 8: Full House
	if (rule[8]) {
		if (a == b && b == c) {
			int res = 3*a;
			if (a == 6)
				res += 2*5;
			else
				res += 2*6;
				
			M = max(M, res);
		}
		else if (a == b || a == c) {
			int r = (a+b+c - 2*a);
			int res = max(3*a + 2*r, 3*r + 2*a);
			
			M = max(M, res);
		}
		else if (b == c) {
			int r = a;
			int res = max(3*b + 2*r, 3*r + 2*b);
			
			M = max(M, res);
		}
	}
	
	if (a != b && a != c && b != c) {
		// 9: Little Straight
		if (rule[9]) {
			if (a != 6 && b != 6 && c != 6) {
				int res= 30;
				M = max(M, res);
			}
		}
		
		// 10: Big Straight
		if (rule[10]) {
			if (a != 1 && b != 1 && c != 1) {
				int res= 30;
				M = max(M, res);
			}
		}
	}
	
	// 11 : Yacht
	if (rule[11]) {
		if (a == b && b == c) {
			int res= 50;
			M = max(M, res);
		}
	}
	
	// 12: Choice
	if (rule[12]) {
		int res = a + b + c + 2*6;
		M = max(M, res);
	}
	
	return M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	bool rule[13] = {};
	for (int i = 1; i <= 12; i++) {
		char x;
		cin >> x;
		rule[i] = (x == 'Y');
	}
	
	int a, b, c;
	cin >> a >> b >> c;
	
	cout << solve(rule, a, b, c);
	
	return 0;
}


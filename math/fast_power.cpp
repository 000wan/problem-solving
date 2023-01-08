#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fast_power(int A, int B, int C) {
	ll a = A % C;
	ll b = B;
	
	ll res = 1;
	while (b > 0) {
		if (b % 2) {
			res = (res * a) % C;
		}
		a = (a * a) % C;
		b /= 2;
	}
	
	return res;
}

int main(void) {
	int A, B, C;
	cin >> A >> B >> C;
	
	cout << fast_power(A, B, C);
}

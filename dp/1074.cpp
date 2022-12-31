#include <iostream>
#include <cmath>
using namespace std;

int zindex(int N, int r, int c) {
	if (N == 0)
		return 0;
	
	int R = r / pow(2, N-1);
	int C = c / pow(2, N-1);
	
	return (R*pow(2, 2*N-1) + C*pow(2, 2*N-2) + zindex(N-1, r-R*pow(2, N-1), c-C*pow(2, N-1)));
}

int main(void) {
	int N, r, c;
	cin >> N >> r >> c;
	
	cout << zindex(N, r, c);
}

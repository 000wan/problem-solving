#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAX_N 10000

int preorder[MAX_N];

void search(int pstart, int pstop, int N) {
	if (pstart > pstop)
		return;
	
	int root = preorder[pstart];
	if (pstart == pstop) {
		cout << root << '\n';
		return;
	}
	
	int i = pstart;
	while (preorder[++i] < root && i < N);
	
	search(pstart+1, i-1, N);
	search(i, pstop, N);
	cout << root << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i = -1;
	while (cin >> preorder[++i]);
	search(0, i-1, i);
	
	return 0;
}


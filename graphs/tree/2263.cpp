#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAX_N 100000

int inorder[MAX_N];
int postorder[MAX_N];

void search(int istart, int istop, int pstart, int pstop) {
	if (istart > istop)
		return;
	
	int root = postorder[pstop];
	if (istart == istop) {
		cout << root << ' ';
		return;	
	}
	
	int i = istart-1;
	while (inorder[++i] != root);
	
	int j = pstart + i - istart;
	
	cout << root << ' ';
	search(istart, i-1, pstart, j-1);
	search(i+1, istop, j, pstop-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	for (int i=0; i<N; ++i)
		cin >> inorder[i];
	for (int i=0; i<N; ++i)
		cin >> postorder[i];
	
	search(0, N-1, 0, N-1);
	
	return 0;
}


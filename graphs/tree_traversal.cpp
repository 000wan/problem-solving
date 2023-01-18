#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define None '.'

unordered_map<char, char> lchild, rchild;
	
void preorder(char current) {
	if (current == None)
		return;
	
	cout << current;
	preorder(lchild[current]);
	preorder(rchild[current]);
}

void inorder(char current) {
	if (current == None)
		return;
	
	inorder(lchild[current]);
	cout << current;
	inorder(rchild[current]);
}

void postorder(char current) {
	if (current == None)
		return;
	
	postorder(lchild[current]);
	postorder(rchild[current]);
	cout << current;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	for (int i=0; i<N; ++i) {
		char node, l, r;
		cin >> node >> l >> r;
		lchild[node] = l;
		rchild[node] = r;
	}
	
	char root = 'A';
	
	preorder(root);
	cout << '\n';
	
	inorder(root);
	cout << '\n';
	
	postorder(root);
	
	return 0;
}


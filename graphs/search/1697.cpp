#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

/*  BOJ #1697  */
int memo[100001];
int solve_DFS(int n, int k) {
	if (n >= k)
		return (n-k);
	if (k == 1) { // exception: k = 1 -> 2 -> 1 -> 2 -> ...
		return 1;
	}
	if (memo[k] != -1) {
		return memo[k];
	}
	
	int res = 100000;
	if (k%2 == 1) {
		res = min(res, 1 + solve_DFS(n, k-1));
		res = min(res, 1 + solve_DFS(n, k+1));
	} else {
		res = min(res, k-n);
		res = min(res, 1 + solve_DFS(n, k/2));
	}
	
	memo[n] = res;
	return memo[n];
}
/* ------------------------------------ */

/*  BOJ 13913 by DFS  */
void check_DFS(int n, int k, int res) {
	if (res == 0) {
		cout << k << ' ';
		return;
	}
	if (k%2 == 1) {
		if (1 + solve_DFS(n, k-1) == res) {
			check_DFS(n, k-1, res-1);
			cout << k << ' ';
		}
		else if (1 + solve_DFS(n, k+1) == res) {
			check_DFS(n, k+1, res-1);
			cout << k << ' ';
		}
	} else {
		if (1 + solve_DFS(n, k-1) == res) {
			check_DFS(n, k-1, res-1);
			cout << k << ' ';
		}
		else if (1 + solve_DFS(n, k+1) == res) {
			check_DFS(n, k+1, res-1);
			cout << k << ' ';
		}
		else if (1 + solve_DFS(n, k/2) == res) {
			check_DFS(n, k/2, res-1);
			cout << k << ' ';
		}
	}
	
	return;
}
/* ------------------------------------ */

/*  BOJ #12851  */
void solve_BFS(int N, int K) {
	int visited[200001][2];
	
	queue<int> pos;
	queue<int> cnt;
	
	pos.push(N);
	cnt.push(0);
	visited[N][0] = 1;
	visited[N][1] = 0;
	
	while (!pos.empty()) {
		int head = pos.front();
		int count = cnt.front();
		pos.pop();
		cnt.pop();
		
		if (head == K) {
			break;
		}
		
		if (head >= 1) {
			if (!visited[head-1][0]) {
				pos.push(head - 1);
				cnt.push(count + 1);
				visited[head-1][1] = count + 1;
			}
			if (visited[head-1][1] == count + 1)
				visited[head-1][0] += visited[head][0];
		}
		if (head < K) {
			if (!visited[head+1][0]) {
				pos.push(head + 1);
				cnt.push(count + 1);
				visited[head+1][1] = count + 1;
			}
			if (visited[head+1][1] == count + 1)
				visited[head+1][0] += visited[head][0];
			
			if (!visited[2*head][0]) {
				pos.push(2*head);
				cnt.push(count + 1);
				visited[2*head][1] = count + 1;
			}
			if (visited[2*head][1] == count + 1)
				visited[2*head][0] += visited[head][0];
		}
	}
	
	cout << visited[K][1] << '\n' << visited[K][0];
	return;
}
/* ------------------------------------ */

/*  BOJ 13913 by BFS  */
void check_BFS(int N, int K) {
	int res = 0;
	int path[200001];
	
	bool visited[200001] = {};
	queue<int> pos;
	queue<int> cnt;
	
	pos.push(N);
	cnt.push(0);
	visited[N] = true;
	
	while (!pos.empty()) {
		int head = pos.front();
		int count = cnt.front();
		pos.pop();
		cnt.pop();
		
		if (head == K) {
			res = count;
			break;
		}
		
		if (head >= 1) {
			if (!visited[head-1]) {
				pos.push(head - 1);
				cnt.push(count + 1);
				path[head-1] = head;
				visited[head-1] = true;
			}
		}
		if (head < K) {
			if (!visited[head+1]) {
				pos.push(head + 1);
				cnt.push(count + 1);
				path[head+1] = head;
				visited[head+1] = true;
			}
			if (!visited[2*head]) {
				pos.push(2*head);
				cnt.push(count + 1);
				path[2*head] = head;
				visited[2*head] = true;
			}
		}
	}
	
	cout << res << '\n';
	
	stack<int> p;
	for(int i = K; i != N; i = path[i]) {
		p.push(i);
	}
	p.push(N);
	
	while (!p.empty()) {
		cout << p.top() << ' ';
		p.pop();
	}
	
	return;
}
/* ------------------------------------ */

int main(void) {
	int N, K;
	cin >> N >> K;
	
	fill_n(memo, 100001, -1);
	int res = solve_DFS(N, K);
	cout << res << '\n';
	check_DFS(N, K, res);
	
	check_BFS(N, K);
}

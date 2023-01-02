/* BOJ #7576 BFS */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Position {
	int x;
	int y;
};

int A[1000][1000];

int BFS(vector<Position> V, int N, int M) {
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	
	queue<Position> pos;
	queue<int> cnt;
	
	bool visited[N][M] = {};
	int count;
	
	for (vector<Position>::iterator i = V.begin(); i != V.end(); i++) {
		Position v = *i;
		pos.push(v);
		cnt.push(0);
		visited[v.x][v.y] = true;
	}
	
	while (!pos.empty()) {
		Position head = pos.front();
		count = cnt.front();
		pos.pop();
		cnt.pop();
		
		int x = head.x;
		int y = head.y;
		for(int i=0; i<4; i++) {
			if (0 <= x+dx[i] && x+dx[i] <= N-1 && 0 <= y+dy[i] && y+dy[i] <= M-1) {
				if (A[x+dx[i]][y+dy[i]] == -1) {
					continue;
				}
				if (visited[x+dx[i]][y+dy[i]])
					continue;
					
				Position w { x+dx[i], y+dy[i] };
					
				pos.push(w);
				cnt.push(count + 1);
				visited[w.x][w.y] = true;
			}
		}
	}
	
	bool flag = true;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (A[i][j] == -1)
				continue;

			if (!visited[i][j]) {
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
	}
	
	if (flag) {
		return count;
	}
	return -1;
}

int main(void) {
	int M, N;
	cin >> M >> N;
	
	vector<Position> starts;
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> A[i][j];
			
			if (A[i][j] == 1) {
				Position v {i, j};
				starts.push_back(v);
			}
		}
	}
	
	cout << BFS(starts, N, M);
}

#include <bits/stdc++.h>
using namespace std;

struct Position {
	int x;
	int y;
};

int A[1000][1000];

int BFS(int N, int M) {
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	
	queue<Position> pos;
    queue<int> lives;
	
	int visited[N][M][2] = {}; // 0: no life, 1: life

    Position start {0, 0};
    pos.push(start);
    lives.push(1);
    visited[0][0][1] = 1;
	
	while (!pos.empty()) {
		Position head = pos.front();
		int life = lives.front();
        pos.pop();
        lives.pop();
		
		int x = head.x;
		int y = head.y;
        int count = visited[x][y][life];

		for(int i=0; i<4; i++) {
			if (0 <= x+dx[i] && x+dx[i] <= N-1 && 0 <= y+dy[i] && y+dy[i] <= M-1) {
				Position w { x+dx[i], y+dy[i] };

                if (A[w.x][w.y] == 1) {
                    if (visited[w.x][w.y][0])
                        continue;

                    if (life) {
                        pos.push(w);
                        lives.push(0);
                        visited[w.x][w.y][0] = count + 1;
                    }
				}
                else {
                    if (visited[w.x][w.y][life])
                        continue;

                    pos.push(w);
                    lives.push(life);
                    visited[w.x][w.y][life] = count + 1;
                } 
            }
		}
	}

    const int INF = (int)1e6 + 1;
    if (!visited[N-1][M-1][0])
        visited[N-1][M-1][0] = INF;
    if (!visited[N-1][M-1][1])
        visited[N-1][M-1][1] = INF;

    int res = min(visited[N-1][M-1][0], visited[N-1][M-1][1]);
    if (res == INF)
        return -1;
    return res;
}

int main(void) {
	int N, M;
	cin >> N >> M;	
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			char x;
            cin >> x;
            A[i][j] = x-'0';
		}
	}
	
	cout << BFS(N, M);
}

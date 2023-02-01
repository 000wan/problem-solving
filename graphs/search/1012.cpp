#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    int T;
    cin >> T;
    
    for(int t=0; t<T; t++) {
        int M, N, K;
        cin >> M >> N >> K;
        int start[K][2];
        bool filled[M][N] = {};
        for(int k=0; k<K; k++) {
            cin >> start[k][0] >> start[k][1];
            filled[start[k][0]][start[k][1]] = true;
        }
        
        int cnt = 0;
        bool visited[M][N] = {};
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        
        stack<int> xs;
        stack<int> ys;
		for(int k=0; k<K; k++) {
			xs.push(start[k][0]);
			ys.push(start[k][1]);
		}
				        
        while(!xs.empty()) {
            int x = xs.top();
            int y = ys.top();
            xs.pop();
			ys.pop();
            if (visited[x][y])
            	continue;
			visited[x][y] = true;
            
            bool flag = false;
            for(int i=0; i<4; i++) {
                if (0 <= x+dx[i] && x+dx[i] <= M-1 && 0 <= y+dy[i] && y+dy[i] <= N-1) {
                    flag = flag || visited[x+dx[i]][y+dy[i]];
					if (filled[x+dx[i]][y+dy[i]]) {
                    	xs.push(x+dx[i]);
						ys.push(y+dy[i]);
					}
				}
            }
            if(!flag)
                cnt++;
        }
        
        cout << cnt << '\n';
    }
    
}

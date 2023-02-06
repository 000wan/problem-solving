#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve(int N) {
    vector<int> prev(3*N, -1);
    std::queue<pair<int,int>> q; // (i, cnt)
    
    int res = 0;
    q.emplace(1, 0);
    while (!q.empty()) {
        auto [i, cnt] = q.front();
        q.pop();
        
        if (i > N)
            continue;
        if (i == N) {
            res = cnt;
            break;
        }

        if (prev[i+1] == -1) {
            q.emplace(i+1, cnt+1);
            prev[i+1] = i;
        }
        if (prev[3*i] == -1) {
            q.emplace(3*i, cnt+1);
            prev[3*i] = i;
        }
        if (prev[2*i] == -1) {
            q.emplace(2*i, cnt+1);
            prev[2*i] = i;
        }
    }
    
    cout << res << '\n';
    int sol = N;
    while (sol != -1) {
        cout << sol << ' ';
        sol = prev[sol];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    solve(N);

    return 0;
}

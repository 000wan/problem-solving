#include <bits/stdc++.h>
#define ll long long
using namespace std;

int D(int n) {
    return (2*n)%10000;
}
int S(int n) {
    return ((n-1) + 10000)%10000;
}
int L(int n) {
    return (n/1000 + (n*10)%10000);
}
int R(int n) {
    return ((n%10)*1000 + n/10);
}

void solve() {
    int a, b;
    cin >> a >> b;
    
    std::queue<pair<int,int>> q;
    std::vector<int> prev(10000, -1);
    std::vector<char> selected(10000, ' ');
    q.emplace(a, 0);

    while (!q.empty()) {
        auto [n, cnt] = q.front();
        q.pop();
        if (n == b)
            break;

        if (prev[D(n)] == -1) {
            q.emplace(D(n), cnt+1);
            prev[D(n)] = n;
            selected[D(n)] = 'D';
        }
        if (prev[S(n)] == -1) {
            q.emplace(S(n), cnt+1);
            prev[S(n)] = n;
            selected[S(n)] = 'S';
        }
        if (prev[L(n)] == -1) {
            q.emplace(L(n), cnt+1);
            prev[L(n)] = n;
            selected[L(n)] = 'L';
        }
        if (prev[R(n)] == -1) {
            q.emplace(R(n), cnt+1);
            prev[R(n)] = n;
            selected[R(n)] = 'R';
        }
    }
    
    std::stack<char> sol;
    int i = b;
    while (i != a) {
        sol.emplace(selected[i]);
        i = prev[i];
    }
    while (!sol.empty()) {
        cout << sol.top();
        sol.pop();
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }    

    return 0;
}

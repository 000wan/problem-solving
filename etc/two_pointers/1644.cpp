#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 4e6;

std::vector<int> prime;
void sieve() {
    bool P[MAX_N+1];
    fill(P, P+MAX_N+1, true);

    for (int i = 2; i <= MAX_N; ++i) {
        if (!P[i])
            continue;
        prime.emplace_back(i);
        for (int j = 1; i*j <= MAX_N; ++j) {
            P[i*j] = false;
        }
    }
}

void solve(int N) {
    const int len = prime.size();
    prime.emplace_back(0); // border
    int sum = prime[0];
    int i = 0, j = 0;
    
    int cnt = 0;
    while (i <= j && j < len) {
        if (sum == N) {
            cnt++;
            sum += prime[++j];
        }
        else if (sum < N)
            sum += prime[++j];
        else
            sum -= prime[i++];
    }

    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int N;
    cin >> N;
    
    solve(N);

    return 0;
}

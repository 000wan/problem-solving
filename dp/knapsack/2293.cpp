#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX_N = 1e2;
const int MAX_K = 1e5;

int N;
int a[MAX_N];

int memo[MAX_K+1];

int solve(int k) {
    memo[0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int w = a[i]; w <= k; ++w) {
            memo[w] += memo[w-a[i]];
        }
    }
    
    return memo[k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
        cin >> a[i];

    cout << solve(K) << '\n';

    return 0;
}

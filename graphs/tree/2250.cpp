#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

#define pii pair<int,int>
const int MAX_N = 1e4;
int parent[MAX_N+1];
pii adj[MAX_N+1];
int N;

int vcnt, lmost[MAX_N+1], rmost[MAX_N+1];
void inorder(int v, int h) {
    if (v == -1) return;
    auto& [l, r] = adj[v];

    inorder(l, h+1);
    vcnt += 1;
    lmost[h] = min(lmost[h], vcnt);
    rmost[h] = max(rmost[h], vcnt);
    inorder(r, h+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    fill(&lmost[1], &lmost[N+1], INF);
    fill(&rmost[1], &rmost[N+1], -INF);
    for (int i = 0; i < N; ++i) {
        int v, l, r;
        cin >> v >> l >> r;
        adj[v] = {l, r};
        if (l != -1) parent[l] = v;
        if (r != -1) parent[r] = v;
    }

    int root = -1;
    for (int i = 1; i <= N; ++i) {
        if (!parent[i]) root = i;
    }

    inorder(root, 1);
    int ind = -1, width = 0;
    for (int h = 1; h <= N; ++h) {
        if (rmost[h]-lmost[h]+1 > width) {
            width = rmost[h]-lmost[h]+1;
            ind = h;
        }
    }
    cout << ind << ' ' << width << '\n';
    
    return 0;
}
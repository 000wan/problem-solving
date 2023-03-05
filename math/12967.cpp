#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    map<ll, ll> g;
    ll a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        g[gcd(K, a[i])] ++;
    }
    vector<ll> v;
    vector<ll> c;
    for (auto& gi : g) {
        v.push_back(gi.first);
        c.push_back(gi.second);
    }
    
    ll res = 0;
    int M = v.size();
    for (int i = 0; i < M; ++i) {
        for (int j = i; j < M; ++j) {
            for (int k = j; k < M; ++k) {
                if ((v[i]*v[j]*v[k])%K) continue;
                
                if (i == j && j == k) {
                    res += c[i]*(c[i]-1)*(c[i]-2)/6;
                }
                else if (i < j && j < k) {
                    res += c[i]*c[j]*c[k];
                }
                else {
                    if (i == j)
                        res += c[i]*(c[i]-1)*c[k]/2;
                    else
                        res += c[k]*(c[k]-1)*c[i]/2;
                }    
            }
        }
    }
    cout << res << '\n';

    return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define pii pair<int,int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    ll res = 0;
    stack<pii> st;
    st.emplace(a[0], 1);
    for (int i = 1; i < N; ++i) {
        int cnt = 1;
        while (!st.empty() && a[i] >= st.top().first) {
            res += st.top().second;
            if (a[i] == st.top().first) {
                cnt += st.top().second;
            }
            st.pop();
        }
        
        if (!st.empty()) res++;
        st.emplace(a[i], cnt);
    }
    cout << res << '\n';
    
    return 0;
}
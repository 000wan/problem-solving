#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 5e5;
int a[MAX_N], tmp[MAX_N];
ll merge_count(int l, int r) {
    if (l == r) return 0;
    int mid = (l+r)/2;
    ll res = merge_count(l, mid) + merge_count(mid+1, r);

    int i = l, j = mid+1;
    for (int k = l; k <= r; ++k) {
        if (i <= mid && (j > r || a[i] <= a[j])) {
            tmp[k] = a[i++];
        } else {
            res += mid-i+1;
            tmp[k] = a[j++];
        }
    }
    for (int k = l; k <= r; ++k) {
        a[k] = tmp[k];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    cout << merge_count(0, N-1) << '\n';

    return 0;
}

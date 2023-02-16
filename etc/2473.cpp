#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e10;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    ll a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a+N);
    
    ll res = INF, sum1 = INF;
    tuple<int,int,int> sol;
    for (int k = 0; k < N-2; ++k) {
        for (int i = k+1; i < N-1; ++i) {
            int j = lower_bound(a+i+1, a+N, -a[k]-a[i])-a;
            if (j == N) j--;
            sum1 = abs(a[k]+a[i]+a[j]);
            if (sum1 < res) {
                res = sum1;
                sol = make_tuple(k, i, j);
            }
            if (j-- > i+1) {
                sum1 = abs(a[k]+a[i]+a[j]);
                if (sum1 < res) {
                    res = sum1;
                    sol = make_tuple(k, i, j);
                }
            }
        }
    }

    cout << a[get<0>(sol)] << ' ';
    cout << a[get<1>(sol)] << ' ';
    cout << a[get<2>(sol)] << ' ';

    return 0;
}

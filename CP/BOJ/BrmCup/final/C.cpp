#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    int a[N], b[M];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a+N);
    for (int i = 0; i < M; ++i) {
        cin >> b[i];
    }
    sort(b, b+M);

    int j = 0;
    for (int i = 0; i < N; ++i) {
        if (j <= a[i]-1 && j < M) {
            b[j]--;
            if (b[j] == 0)
                j++;
        }
    }

    bool flag = true;
    for (int i = 0; i < M; ++i) {
        flag = flag && (b[i] == 0); 
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

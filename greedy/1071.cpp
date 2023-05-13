#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a+N);

    for (int i = 0, j; i < N-1; ++i) {
        if (a[i]+1 == a[i+1]) {
            j = i+1;
            while (j < N && a[i]+1 == a[j]) j++;
            if (j < N) {
                swap(a[i+1], a[j]);
                continue;
            }

            j = i;
            while (j >= 0 && a[i] == a[j]) j--;
            swap(a[i+1], a[j+1]);
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " \n"[i==N-1];
    }
    
    return 0;
}
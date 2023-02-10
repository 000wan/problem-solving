#include <bits/stdc++.h>
#define ll long long
using namespace std;

int sum(int a) {
    if (a == 0) return 0;
    return a%10+sum(a/10);
}

void solve() {
    int N;
    cin >> N;
    
    int a = 0, b = 0;
    int i = 1;
    while (N) {
        int k = N%10;
        if (k%2 == 0)
            a += i*(k/2), b += i*(k/2);
        else {
            k = (k-1)/2;
            if (a >= b)
                a += i*(k), b += i*(k+1);
            else
                b += i*(k), a += i*(k+1);
        }
        i *= 10;
        N /= 10;
    }

    cout << a << ' ' << b << '\n';
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

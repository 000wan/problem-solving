#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define all(x) (x).begin(),(x).end()

// FFT : multiplying two polynomials in O(nlogn)
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int)a.size() + (int)b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    string a, b; cin >> a >> b;
    vector<int> x, y;
    for (int i = a.size()-1; i >= 0; --i)
        x.push_back(a[i]-'0');
    for (int i = b.size()-1; i >= 0; --i)
        y.push_back(b[i]-'0');
    
    auto res = multiply(x, y);
    for (int i = 0, carry = 0; i < res.size(); ++i) {
        res[i] += carry;
        carry = res[i] / 10;
        res[i] %= 10;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    for (int i = res.size()-1; i >= 0; --i) {
        cout << res[i];
    }
    
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const ll MOD = 1e6+3;
struct Matrix {
    int N;
    vector<vector<ll>> arr;
    Matrix(int N): N(N), arr(vector<vector<ll>>(N, vector<ll>(N, 0))){}
    Matrix(int N, bool id) {
        Matrix a = Matrix(N);
        for (int i = 0; i < N; ++i) {
            a.arr[i][i] = 1;
        }
        this->N = a.N;
        this->arr = a.arr;
    }
    Matrix operator * (const Matrix& b) {
        Matrix c(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    c.arr[i][j] += arr[i][k]*b.arr[k][j];
                    c.arr[i][j] %= MOD;
                }
            }
        }
        return c;
    }
    Matrix pow(ll b) {
        Matrix a = *this;
        Matrix ret (N, true);
        while (b > 0) {
            if (b&1) ret = ret*a;
            a = a*a;
            b >>= 1;
        }
        return ret;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, S, E, T;
    cin >> N >> S >> E >> T;
    S--, E--;

    Matrix a(5*N);
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j < 5; ++j) {
            a.arr[5*i+j][5*i+j-1] = 1;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char x; cin >> x; x -= '0';
            if (x > 0)
                a.arr[5*i][5*j+x-1] = 1;
        }
    }

    Matrix res = a;
    res = res.pow(T);
    cout << res.arr[5*S][5*E] << '\n';

    return 0;
}
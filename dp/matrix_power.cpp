#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const ll MOD = 1e9+7;
struct Matrix {
    int N;
    vector<vector<ll>> arr;
    Matrix(int N): N(N), arr(vector<vector<ll>>(N, vector<ll>(N, 0))){}
    Matrix(int N, vector<vector<ll>> arr): N(N), arr(arr){}
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
    
    ll N;
    cin >> N;
    
    vector<vector<ll>> Ad = {
        {0, 2, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 0},
        {0, 1, 0, 0}
    };
    Matrix A(4, Ad);
    A = A.pow(N-1);
    ll res = (A.arr[0][1]+A.arr[0][2])%MOD;
    cout << res << '\n';

    return 0;
}
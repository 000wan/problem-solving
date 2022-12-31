#include <iostream>
#include <cmath>
using namespace std;

int count(int x, int base) {
    int res = 0;
    long int i = base;
    while (x/i > 0) {
        res += x/i;
        i *= base;
    }
    return res;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    
    int res2 = count(n, 2) - count(m, 2) - count(n-m, 2);
    int res5 = count(n, 5) - count(m, 5) - count(n-m, 5);
    
    cout << min(res2, res5);
}

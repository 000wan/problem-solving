#include <iostream>
#include <unordered_map>
using namespace std;

#define SUP 1000000007

int main(void) {
    int N;
    cin >> N;
    
    unordered_map<int,int> table;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        table[A]++;
    }
    
    long int res = 1;
    for(auto a : table) {
    	res *= (1 + a.second);
    	res %= SUP;
    }
    res = (res-1) % SUP;
    
    cout << res;
}

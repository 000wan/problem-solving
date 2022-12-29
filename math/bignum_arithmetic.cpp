#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int digit[10001] = {};
    
    for(int i = 0; i < 2; i++) {
        char S[10001];
		cin >> S;
		int j = -1;
        while(S[++j] != '\0');
		reverse(S, S + j);
		
		for(int k = 0; k < j; k++) {
			char c = S[k];
            digit[k] += (int(c)-48);
		}
	}
    
    int carry = 0;
    for(int i = 0; i < 10001; i++) {
        int d = digit[i] + carry;
        carry = d / 10;
        digit[i] = d % 10;
    }
    
    bool flag = true;
    for(int i = 10000; i >= 0; i--) {
        flag = flag && (digit[i] == 0);
        if (!flag) {
            cout << digit[i];
        }
    }    
}

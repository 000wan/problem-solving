#include <iostream>
using namespace std;

int main(void) {
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++) {
    	int A, B, C, p;
    	cin >> A >> B >> C >> p;
    	
    	int pdouble = 0;
    	pdouble += (int)(A % p == 0);
    	pdouble += (int)(B % p == 0);
    	pdouble += (int)(C % p == 0);
    	
    	if (pdouble >= 2) {
    		cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}

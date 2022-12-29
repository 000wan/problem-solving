#include <iostream>
using namespace std;

int main(void) {
    int x;
    cin >> x;
    if (x == 1) {
        cout << 1;
    }
    else {
    	int n = 1;
	    int an = 2;
	    while(true) {
	        if (an <= x && x < an+6*n)
	            break;
	        an += 6*n;
	        n++;
	    }
	    cout << n+1;
	}
}

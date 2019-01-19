#include <iostream>
using namespace std;

int getResult(int a, int b, int c){
    if (b == 0) {
        return 1;
    }
    
    if (b == 1) {
        return a%c;
    }
    
    int left, right;
    left = getResult(a, b/2, c);
    right = getResult(a, b - b/2, c);
    
    return (left*right)%c;
}

int main() {
	//code
	int t, a, b, c;
	cin>>t;
	for (int i=0; i<t; i++) {
	    cin>>a;
	    cin>>b;
	    cin>>c;
	    
	    cout<<getResult(a,b,c)<<endl;
	}
	return 0;
}

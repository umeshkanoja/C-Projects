#include <iostream>
using namespace std;

int main() {
	//code
	int t, n, size;
	cin>>t;
	for (int i=0; i<t; i++) {
	    cin>>n;
	    int *a;
	    size=n*n;
	    a = new int[size];
	    for (int j = 0; j<size; j++){
	        cin>>a[j];
	    }
	    
	    for (int j=0; j<n; j++){
	        for (int k=1; k<=n; k++){
	            cout<<a[size - n*k + j]<<" ";
	        }
	    }
	    
	    cout<<endl;
	}
	return 0;
}

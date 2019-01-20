#include <iostream>
using namespace std;

void visitX(char **a, int i, int j, int m, int n){
    int x[4] = {-1, 0, 0, 1}, y[4]={0, -1, 1, 0};
    
    if (a[i][j] != 'X') return;
    a[i][j] = 'O';
    for (int k=0; k<4; k++){
        int p = i + y[k], q = j + x[k];
        if (p >= 0 && q>=0 && p<m && q<n && a[p][q]=='X'){
            visitX(a, p, q, m, n);
        }
    }
}

int main() {
	//code
	int t,r,c,regions;
	cin>>t;
	for (int p=0; p<t; p++){
	    cin>>r;
	    cin>>c;
	    regions=0;
	    char **a = new char*[r], dummy;
	    for (int i=0; i<r; i++){
	        a[i] = new char[c];
	        for (int j=0; j<c; j++){
	            cin>>a[i][j];
	        }
	    }
	    
	    for (int i=0; i<r; i++){
	        for (int j=0; j<c; j++){
	            if (a[i][j] == 'X') {
	                regions++;
	                visitX(a, i, j, r, c);
	            }
	        }
	    }
	    
	    cout<<regions<<endl;
	}
	
	return 0;
}

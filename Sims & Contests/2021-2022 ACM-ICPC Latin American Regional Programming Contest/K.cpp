#include <bits/stdc++.h>
#ifdef jlocal
#include<jdebug/debug.hpp>
#else
#define debug(...) 0;
#endif
using namespace std;

#define endl "\n"
#define repf(i,k,n) for(int i=k; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)

typedef vector<int> vi;
typedef long long ll;

int main(){
	int n; cin >> n;
	vector<string> A(n);
	set<char> letras;
	rep(i, n) {
		cin >> A[i];
		letras.insert(A[i][0]);
	}

	rep(i, n){
		bool correct = true;
		rep(j, A[i].size()){
			if (letras.find(A[i][j]) == letras.end()){
				correct = false;
				break;
			}
		}
		if (correct) {
			cout << "Y" << endl;
			return 0;
		}
		
	}
	cout << "N" << endl;
	return 0;
}
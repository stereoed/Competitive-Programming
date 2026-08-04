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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi a(n);
	rep(i,n)cin>>a[i];
	int m;
	cin >> m;
	vi b(m);
	rep(i,m)cin>>b[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int salida = 0;
	rep(i,n){
		rep(j,m){
			if(abs(a[i]-b[j])<=1){
				debug(i);
				debug(j);
				debug(a[i]);
				debug(b[j]);
				b[j]=1000;
				salida++;

				break;
			}
		}
	}
	cout << salida << endl;
	return 0;
}
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
	vi non;
	int pig = 0;
	rep(i,n){
		string a;
		cin >> a;
		int x;
		cin >> x;
		if(a=="pig"){
			pig = max(pig,x);
		}else{
			non.push_back(x);
		}
	}
	ll tot = pig;
	sort(non.begin(),non.end());
	rep(i,non.size()){
		if(non[i]>=pig)break;
		tot+=non[i];
	}
	cout << tot << endl;
	return 0;
}
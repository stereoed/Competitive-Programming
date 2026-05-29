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
	ll n, s = 0, o = 0; cin >> n;

	vector<ll> v(n), mi(n + 1), su(n + 1); 
	rep(i, n) { cin >> v[i]; s += llabs(v[i]); }


	repf(i, 1, n + 1){
		if (v[i - 1] > 0) su[i] = su[i-1] + v[i - 1];
		else su[i] = su[i-1] + 3 * v[i - 1];
		
		mi[i] = min(su[i], mi[i - 1]);
	}

	rep(i, n + 1) o = max(su[i] - mi[i], o);

	cout << s + o << endl;

	return 0;
}
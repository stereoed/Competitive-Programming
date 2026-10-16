#include <bits/stdc++.h>
#ifdef jlocal
#include<jdebug/debug.hpp>
#else
#define debug(...) 0;
#endif
using namespace std;

//#define endl "\n"
#define repf(i,k,n) for(int i=k; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)

typedef vector<int> vi;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N; cin >> N;
	ll x = 1;

	string ans = "";
	ll then = 0;
	while (x < N){
		string cur = to_string(N - x) + to_string(x);

		if (cur.size() > ans.size()){
			ans = cur;
			then = N - x;
		} else if (cur.size() == ans.size() && to_string(N - x) > to_string(then)){
			then = N - x;
			ans = cur;
		}

		x *= 10;
	}

	cout << ans << endl;

	return 0;
}
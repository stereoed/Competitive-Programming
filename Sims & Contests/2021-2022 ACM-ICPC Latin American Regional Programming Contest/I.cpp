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

int delta[7] = {30, 30, 30, 32, 31, -1, -1};

int main(){
	string s; int n;
	int day, ans = 1e9;
	cin >> s >> n;

	if (s == "Mon") day = 0;
	else if (s == "Tue") day = 1;
	else if (s == "Wed") day = 2;
	else if (s == "Thu") day = 3;
	else if (s == "Fri") day = 4;
	else if (s == "Sat") day = 5;
	else if (s == "Sun") day = 6;

	rep(i, n){
		int x; cin >> x;
		int aux = ((day - x) % 7 + 7) % 7;

		if (aux == 1 && x > 30){
			aux = 3;
			x -= 30;
		}

		if (aux == 3 && x > 32){
			aux = 0;
			x -= 32;
		}

		if (x > 91) x %= 91;

		while (x > delta[aux]){
			x -= delta[aux];
			aux += 2;

			if (aux > 4) aux = 0;
		}

		aux += 30;
		aux %= 7;
		x = 30 - x + (aux > 4 ? 7 - aux : 0);
		ans = min(x, ans);
	}

	cout << ans << endl;
}
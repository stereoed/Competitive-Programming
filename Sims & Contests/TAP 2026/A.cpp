#include <bits/stdc++.h>

typedef long long ll;

using namespace std;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	bool minus = false, more = true;

	int H, M, S; cin >> H >> M >> S;
	if (H == 2 && M == 30 && S == 0){
		cout << '=' << endl;
		return 0;
	}

	if (H < 2 || (H == 2 && M < 30)) minus = true;

	cout << (minus ? '-' : '+') << endl;
	return 0;
}


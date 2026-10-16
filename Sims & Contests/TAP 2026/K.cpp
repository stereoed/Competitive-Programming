#include <bits/stdc++.h>

typedef long long ll;

using namespace std;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<ll> valores = {0, 5, 1, 6, 2, 7, 3, 8, 4};
	for(int i = 0; i < n; i++){
		int r;
		cin >> r;
		cout << valores[r] << " ";
	}
	cout << endl;

	return 0;
}


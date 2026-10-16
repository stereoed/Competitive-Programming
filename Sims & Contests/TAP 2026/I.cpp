#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, K; cin >> N >> K;
	if (K == 1 || (N == 2 && (K & 1))) cout << "S\n";
	else cout << "N\n";
	return 0;
}


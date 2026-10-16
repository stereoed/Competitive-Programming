#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M; cin >> N >> M;
	vector<int> V(N), C(N), IZQ(M + 5), DER(M + 5);

	for (auto& x : V) cin >> x;
	C = V;

	sort(C.begin(), C.end());
	C.erase(unique(C.begin(), C.end()), C.end());

	for (int i = 0; i < N; i++) {
		int next = upper_bound(C.begin(), C.end(), V[i]) - C.begin();
		if (next < N) IZQ[V[i]] = max(V[i], IZQ[C[next]]);
		else IZQ[V[i]] = V[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		int next = upper_bound(C.begin(), C.end(), V[i]) - C.begin();
		if (next < N) DER[V[i]] = max(V[i], DER[C[next]]);
		else DER[V[i]] = V[i];
	}

	int ans = 0, ptr = -1e9;
	while (ptr != C.back()){
		int next = upper_bound(C.begin(), C.end(), ptr) - C.begin();
		ptr = max(IZQ[C[next]], DER[C[next]]);
		ans++;
	}
	
	cout << (int)C.size() << " " << ans << '\n';
	return 0;
}


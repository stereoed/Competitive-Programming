#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
const int MOD = 1e9 + 7;
const int INF = 1e9;
 
int n, m;
vii mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
 
void solve() {
	cin >> n >> m;
	vector<string> arr(n); rep(i, n) cin >> arr[i];
	vector<vector<bool>> seen(n, vector<bool>(m));
	ll ans = 0;
	
	rep(i, n){
		rep(j, m){
			if (seen[i][j] || arr[i][j] == '#') continue;
			ans++;
			
			queue<pii> q;
			q.push({i, j});
			seen[i][j] = 1;
			
			while (!q.empty()){
				auto [x, y] = q.front(); q.pop();
				for (auto& [dx, dy] : mov){
					int nx = x + dx, ny = y + dy;
					
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (arr[nx][ny] == '#' || seen[nx][ny]) continue;
					
				    seen[nx][ny] = 1;
					q.push({nx, ny});
				}
			}
		}
	}
	
	cout << ans << el;
}
 
int main() {
	FastIO;
	int t = 1;
	while (t--) solve();
	return 0;
}
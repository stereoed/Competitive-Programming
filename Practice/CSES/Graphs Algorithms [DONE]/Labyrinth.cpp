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
vector<tuple<int, int, char>> mov = {{1, 0, 'D'}, {-1, 0, 'U'}, {0, 1, 'R'}, {0, -1, 'L'}};
string ans = "";
 
bool bfs(int x, int y, vector<string>& arr, vector<vector<bool>>& seen){
    
}
 
void solve() {
	cin >> n >> m;
	vector<string> arr(n); rep(i, n) cin >> arr[i];
	vector<vector<char>> dir(n, vector<char>(m));
    queue<pii> q;
	pii B;
	
	rep(i, n)
		rep(j, m){
			if (arr[i][j] == 'A'){ q.push({i, j}); dir[i][j] = 'A'; }
			if (arr[i][j] == 'B'){ B.first = i; B.second = j; }
		}
    
	while (!q.empty()){
	    auto [x, y] = q.front(); q.pop();
    	for (auto& [dx, dy, c] : mov){
    		int nx = x + dx, ny = y + dy;
    	
    		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
    		if (arr[nx][ny] == '#' || dir[nx][ny]) continue;
    		
    	    dir[nx][ny] = c;
    		q.push({nx, ny});
    	}
	}
	
	if (!dir[B.first][B.second]){
	    cout << "NO" << el;
	    return;
	}
	
	q.push(B);
	while (!q.empty()){
	    auto [x, y] = q.front(); q.pop();
	    pii M = {0, 0};
	    char& c = dir[x][y];
	    
	    if (c == 'L') M = {0, 1};
	    if (c == 'R') M = {0, -1};
	    if (c == 'D') M = {-1, 0};
	    if (c == 'U') M = {1, 0};
	    if (c == 'A') break;
	    ans += c;
	    
    	q.push({x + M.first, y + M.second});
	}
	
	reverse(all(ans));
	cout << "YES" << el;
	cout << ans.size() << el;
	cout << ans << el;
}
 
int main() {
	FastIO;
	int t = 1;
	while (t--) solve();
	return 0;
}
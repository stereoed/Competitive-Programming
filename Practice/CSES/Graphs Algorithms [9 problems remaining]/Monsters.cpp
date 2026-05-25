#pragma GCC optimize("Ofast")
 
#if __has_include("stdc++.h")
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif
 
#ifdef LOCAL
    #if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
    #else
    #define dump(...)
    #endif
#else
    #define dump(...)
#endif
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
const int MOD = 998244353;
const int INF = 1e9;
 
struct delta {
	int x, y;
	char dir;
};
 
struct node {
	int step = 0;
	int px = -1, py = -1;
	bool seen = false;
	char c = 0, move = 'S';
};
 
delta D[] = {{0, 1, 'R'}, {0, -1, 'L'}, {1, 0, 'D'}, {-1, 0, 'U'}};
 
bool boundary(int x, int y, int n, int m) {
	return x == 0 || x == n - 1 || y == 0 || y == m - 1;
}
 
/*
	PROBLEMA ACTUAL (NO EN CONTEST).
	MONSTERS - Multi BFS
*/
 
void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> v(n); rep(i, n) cin >> v[i];
 
	vector<vector<node>> seen(n, vector<node>(m));
	queue<pii> q;
	pii st = {-1, -1};
 
	// Primero metes TODOS los monstruos.
	rep(i, n) {
		rep(j, m) {
			if (v[i][j] == '#') {
				seen[i][j].seen = 1;
				seen[i][j].c = '#';
			}
			else if (v[i][j] == 'M') {
				node& cur = seen[i][j];
				cur.seen = 1;
				cur.step = 0;
				cur.c = 'M';
				cur.move = 'S';
				q.push({i, j});
			}
			else if (v[i][j] == 'A') {
				st = {i, j};
			}
		}
	}
 
	// Luego metes A al final.
	{
		auto [x, y] = st;
		node& cur = seen[x][y];
		cur.seen = 1;
		cur.step = 0;
		cur.c = 'A';
		cur.move = 'S';
		q.push({x, y});
	}
 
	pii fin = {-1, -1};
 
	// Si A parte en borde, ya ganó.
	if (boundary(st.first, st.second, n, m)) fin = st;
 
	while (!q.empty() && fin.first == -1) {
		auto [x, y] = q.front(); q.pop();
		node& cur = seen[x][y];
 
		for (auto [dx, dy, dir] : D) {
			int i = x + dx, j = y + dy;
 
			if (i < 0 || i >= n || j < 0 || j >= m) continue;
			if (seen[i][j].seen) continue;
 
			node& nxt = seen[i][j];
			nxt.seen = 1;
			nxt.px = x;
			nxt.py = y;
			nxt.step = cur.step + 1;
			nxt.c = cur.c;
			nxt.move = dir;
 
			q.push({i, j});
 
			if (nxt.c == 'A' && boundary(i, j, n, m)) {
				fin = {i, j};
				break;
			}
		}
	}
 
	if (fin.first == -1) {
		cout << "NO" << el;
		return;
	}
 
	string path;
	auto [x, y] = fin;
 
	while (!(x == st.first && y == st.second)) {
		path.pb(seen[x][y].move);
		int px = seen[x][y].px;
		int py = seen[x][y].py;
		x = px;
		y = py;
	}
 
	reverse(all(path));
 
	cout << "YES" << el;
	cout << path.size() << el;
	cout << path << el;
}
 
int main() {
	FastIO;
	solve();
	return 0;
}
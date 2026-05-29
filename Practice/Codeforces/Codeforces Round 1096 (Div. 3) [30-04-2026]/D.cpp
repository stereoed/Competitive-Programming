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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef tuple<ll, ll, ll> tiii;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

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
const double EPS = 1e-9;
const int INF = 1e9;
const ll INFL = 1e17;

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll floor(ll a, ll b) { return a / b - (a % b < 0); }
ll ceil(ll a, ll b) { return a / b + (a % b > 0); }

template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}

struct delta{
	int x, y;
	char dir;
};

struct edge{
	int a, b;
	ll w;
};

delta D[] = {{0, 1, 'R'}, {0, -1, 'L'}, {1, 0, 'D'}, {-1, 0, 'U'}};

ll n, m, query;
vector<edge> edges;
vi v;

void solve() {
	cin >> n;
	v = vi(2 * n); cin >> v;
	
	// Encontrar los centros te los palindromos
	set<int> center;
	vi other(2*n, -1);
	rep(i, 2*n){
		ll& a = v[i];
		if (other[a] == -1) other[a] = i;
		else center.insert(i + other[a]);
	}
	
	dump(center);
	
	// Bescar por cada palindromo
	ll ans = 1, k;
	vb seen(n + 1);
	while (!center.empty()){
		int c = *center.begin();
		center.erase(c);
		
		bool par = c & 1;
		c /= 2;
		
		ll l = c, r = c + par;
		
		if (v[l] != v[r]) continue;
		
		seen[v[c]] = 1;
		
		while (l - 1 >= 0 && r + 1 < 2 * n && v[l - 1] == v[r + 1]){
			seen[v[--l]] = 1;
			seen[v[++r]] = 1;
		}
		
		k = 0;
		while (seen[k]) k++;
		ans = max(ans, k);
		
		seen = vb(n + 1);
	}
	
	cout << ans << el;
}

int main() {
	FastIO;

#ifdef LOCAL
	auto start = chrono::high_resolution_clock::now();
#endif

	int t = 1;
	cin >> t;
	
	while (t--) {
		solve();
	}

#ifdef LOCAL
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> elapsed = end - start;
	cerr << "\n[Time] " << fixed << setprecision(6) << elapsed.count() << " ms\n";
#endif

	return 0;
}
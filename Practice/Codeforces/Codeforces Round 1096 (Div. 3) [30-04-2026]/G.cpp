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

// ORDERED TREE
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;


#define ordered_set tree<pair<ll, int>, null_type,less<pair<ll, int>>, rb_tree_tag,tree_order_statistics_node_update>

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

ll n, m;
vector<edge> edges;
vi v;


/*
*
* Drowning - DIV 3
* PROBLEMA: https://codeforces.com/contest/2227/problem/G
* EDITORIAL: https://codeforces.com/blog/entry/153099
* 
* Como el arreglo mantiene la paridad, tiene que ser impar.
* Si x = c_(i-1) - c_(i) + c_(i+1), entonces x > 0. Por lo tanto la 
* diferencia entre R y L debe ser positiva.
*
* Podemos entonces aprovechar que "order_of_key(x): Returns the number
* of elements strictly smaller than x" para encontrar cuantos se pueden hacer.
*
*/


void solve() {
	// Inicializacion e input.
	cin >> n;
	v = vi(n); cin >> v;
	ll ans = 0;

	/*
	* oset[2] nos permite jugar con la paridad
	* Para que acepte grupos de uno: oset[0].insert({0LL, 0}); 
	*/
	ordered_set oset[2];
    oset[0].insert({0LL, 0}); 
	
	ll val = 0;
	/*
	* val -> alternating sum
	* oset[(i)%2].order_of_key({val, -1}); Agrega los de la misma paridad que sean menor estricto
	* oset[(i+1)%2].insert({-val, i}); Agrega el inverso a la otra paridad.
	*/
	rep(i, n){
        val = v[i] - val;
		// Agregamos los impares 
        ans += oset[(i)%2].order_of_key({val, -1});
        oset[(i+1)%2].insert({-val, i});
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
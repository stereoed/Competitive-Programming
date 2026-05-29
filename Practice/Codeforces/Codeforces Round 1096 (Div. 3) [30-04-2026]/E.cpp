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

ll n, m, ans;
vector<edge> edges;
vi v;

/*
	Por nivel ans += cubos que tienen un espacio a la derecha.
	Puedo ir de derecha a izquierda buscando los primeros espacios en cada nivel.
	Tipo, minimo hasta ahora, y luego relleno desde ese hasta el minimo anterior con el indice.
	
	Las siguientes iteraciones agrego las que estan encima del minimo minimo al total de cubos que se mueven.
	
	Como implemento la operacion?
	Casi seguro que es una dp, cant[llega a x][hasta col]
	Si elimino en k se agrega J, con J siendo la distancia a la izq hasta el primero que sea menor.
*/

void solve() {
	cin >> n;
	v = vi(n); cin >> v;
	vi freq(n + 1, 0), h(n);
	
	ans = 0;
	ll min_h = INF;
	ll max_comodin = 0;
	

	repb(i, n){
		// Base (sin eliminar cubo)
		if (v[i] < min_h) min_h = v[i];
		ans += max(0LL, v[i] - min_h);
		
		h[i] = min_h;
	}
	
	ll cur = h[0], cnt = 0;
	dump(v, h);
	rep(i, n){
		dump(cur, cnt, h[i] == cur, max_comodin);
		if (h[i] == cur) cnt ++;
		else {
			max_comodin = max(max_comodin, cnt - 1);
			cnt = 1;
			cur = h[i];
		}
	}
	dump(cur, cnt);
	max_comodin = max(max_comodin, cnt - 1);
	dump(ans, max_comodin);
	cout << ans + max_comodin << el;
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
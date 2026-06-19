#pragma GCC optimize("Ofast")

#if __has_include("stdc++.h")
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#ifdef LOCAL
    #if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
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
#define imp "IMPOSSIBLE"
#define yes "Y"
#define no "N"

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

const int MAXN = 2005;

int w, h, n;

/*
* Hay cuatro casos en los que falla 
* Vertical + horizontal:
*
* 5 5
* 2
* 4 0 3 5
* 5 3 0 2
*
* Vertical + vertical pero se cruza:
* 
* 5 5
* 2
* 1 0 1 5
* 0 0 2 5 
*
* Horizontal + horizontal pero se cruza
*
* 5 5
* 2
* 0 1 5 1
* 0 0 5 2 
*
* Para estos ultimos dos casos lo podemos interpretar como
* un intervalo que si es contenido por otro -> infactible.
*
* De pared vertical a pared horizontal
* 3 3
* 2
* 0 2 1 3
* 0 3 2 0
*/

struct point{
	int x1, y1, x2, y2;
	bool border = false;
};

ll getp(ll x, ll y){
    if (y == 0) return x;
    if (x == w) return w + y;
    if (y == h) return w + h + (w - x);
    return w + w + h + (h - y);
}

void solve() {
	cin >> w >> h >> n;
	vector<point> vp(n);
	
	rep(i, n){
		point& p = vp[i];
		cin >> p.x1 >> p.y1 >> p.x2 >> p.y2;
		
		if (p.x1 == 0 || p.x1 == w || p.y1 == 0 || p.y1 == h){
			if (p.x2 == 0 || p.x2 == w || p.y2 == 0 || p.y2 == h){
				p.border = 1;
			}
		}		
	}
	
	/*
		Ahora para el caso 4. n  = 1e5
		Pensaba en separa el cuadrado y luego ver si los puntos estan conectados de un area a otra. Es dificil partir lw en dos para cada una entonces mejor buscar otra solucion: se podra integrar al sistema de antes?
		eee
		lei hint: puede ser como un parentesis
	*/
	
	vii dist;
	int i = 0;
	for (point p : vp){
		if (p.border){
			dist.pb({getp(p.x1, p.y1), i});
			dist.pb({getp(p.x2, p.y2), i});
			i++;
		}
	}
	
	sort(all(dist));
	dump(dist)
	vb seen(i);
	vi stack;
	
	for (auto [p, id] : dist){
		dump(seen[id])
		dump(stack)
		
		if (!seen[id]){
			seen[id] = true;
			stack.pb(id);
			continue;
		}
		
		if (id != stack.back()){
			cout << no << el;
			return;
		}
		
		stack.pop_back();
	}
	
	
	cout << yes << el;
	
	
}

int main() {
	FastIO;

#ifdef LOCAL
	auto start = chrono::high_resolution_clock::now();
#endif

	int t = 1;
	//cin >> t;
	
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
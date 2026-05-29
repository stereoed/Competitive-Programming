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

ll n, m;
vector<edge> edges;
vi v;


/*
*
* It Just Keeps Going Sideways - DIV 3
* PROBLEMA: https://codeforces.com/contest/2227/problem/F
* EDITORIAL: https://codeforces.com/blog/entry/153099
* 
*/


void solve() {
	// Inicializacion e input.
	cin >> n;
	v = vi(n); cin >> v;
	vi cnt(n + 1, 0);
	
	// Cantidad de torres con tamano (==) y (>=) a i.
	repb(i, n) cnt[v[i]] += 1;
	vi cnt_exact = cnt;
	
	repb(i, n) cnt[i] += cnt[i + 1];
	dump(v, cnt_exact, cnt);
	
	/* 
	* Parte base del problema O(n)
	* Buscamos usar la diferencia por peso entre pos inicial y pos final para encontrar 
	* cuanto se movio cada cosa.
	*
	* Inicial es la posicion actual * cantidad de cubos -> (i + 1) * v[i]. Usamos 1-IDX
	* porque la primera columna tiene distancia 1, no 0. Asi es mas seguro
	*
	* Para calcular la posicion final sabemos que vamos a tener cnt[i] cuadrados pegados a la
	* derecha por cada altura i. Si fijo la altura de la torre, solo sumo las posiciones.
	*
	* Sum (k = n - cnt[i] + 1, n) (k * 1) 
	* Transformandolo a O(1) : [n * (n - 1) / 2] - [n - cnt[i + 1] * (n - cnt[i + 1] + 1) / 2]
	*/
	
	ll pos_final = 0, pos_inicial = 0, total = n * (n + 1) / 2;
	rep(i, n){
		pos_inicial += (i + 1) * v[i];
		pos_final += total - ((n - cnt[i + 1]) * (n - cnt[i + 1] + 1) / 2);
	}
	
	ll base = pos_final - pos_inicial;
	dump(pos_inicial, pos_final, base);
	
	/* 
	* Parte operatoria del problema
	* Si quitamos una pieza de la columna i --> cnt[v[i]] -= 1. Es decir, el resto de
	* cnt se mueve uno mas a la derecha.
	* En otras palabras, nuestro ultimo cuadradito (el mas a la izq) y no existe.
	* Este cuadrado se ubica en n - cnt[i] + 1 (Se suma).
	* Pero tambien hay que eliminar ese cuadrado en su posi inicial.
	*/
	
	ll operacion = 0;
	rep(i, n){
		ll delta_pos_inicial = i;
		ll delta_pos_final = n - cnt[v[i]];
		operacion = max(operacion, delta_pos_inicial - delta_pos_final);
	}
	
	dump(operacion);
	dump(base + operacion);
	cout << base + operacion << el;
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
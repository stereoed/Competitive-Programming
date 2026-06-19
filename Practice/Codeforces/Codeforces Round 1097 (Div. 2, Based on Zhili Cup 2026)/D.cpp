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
#define yes "YES"
#define no "NO"

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

int n, m;

int fast_power_mod(int x, int k){
    int r = 1;
    
    while(k){
        if (k & 1){
            r = r * 1ll * x % MOD;
        }
        x = x * 1ll * x % MOD;
        k /= 2;
    }
    
    return r;
}

struct frac{
    int x, y;
    bool operator<(const frac&t)const{
        return x * 1ll * t.y < t.x * 1ll * y;
    }
};

void solve() {
    cin >> n;
    vi A(n), B(n); cin >> A >> B;
    vector<frac> fA(n * n), fB(n * n);
    int tA = 0, tB = 0;
    ll sum = 0;
    
    rep(i, n) rep(j, n){
        if (j != i) fB[tB++] = {(int)B[i], (int)B[j]};
        if (j > i) fA[tA++] = {(int)A[i], (int)A[j]};
    }
    
    fA.resize(tA);
    fB.resize(tB);
    sort(all(fA));
    sort(all(fB));
    
    int j = 0;
    rep(i, tA){
        while (j < tB && fB[j] < fA[i]) j++;
        sum += j;
    }
    
    cout << sum % MOD * fast_power_mod(1ll * n * (n - 1) % MOD, MOD - 2) % MOD << el;
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
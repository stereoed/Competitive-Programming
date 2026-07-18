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

const int MAXN = 500;
int n;
ll a;
string k;
vi nums;

string mayorMenorIgual(string a) {
    int mx = nums.back();
    string res;

    rep(i, a.size()){
        int dig = a[i] - '0';
        int idx = upper_bound(nums.begin(), nums.end(), dig) - nums.begin() - 1; // (<=)

        if (idx >= 0) {
            res.push_back('0' + nums[idx]);
            if (nums[idx] < dig) {
                // Rellenar con maximo
                while ((int)res.size() < (int)a.size()) res.push_back('0' + mx);
                return res;
            }
            
        } else {
            while (!res.empty()) {
                int last = res.back() - '0';
                res.pop_back();

                int idx2 = lower_bound(nums.begin(), nums.end(), last) - nums.begin() - 1; // (<)
                if (idx2 >= 0) {
                    // Rellenar con maximo
                    res.push_back('0' + nums[idx2]);
                    while ((int)res.size() < (int)a.size()) res.push_back('0' + mx);
                    return res;
                }
            }
            
            // No se puede misma cantidad de digitos
            if (a.size() == 1) return "";
            return string(a.size() - 1, '0' + mx);
        }
    }
    
    return res;
}

string menorMayorIgual(string a) {
    int mi = nums.front();
    int n = nums.size();
    string res;

    rep(i, a.size()) {
        int dig = a[i] - '0';
        int idx = lower_bound(nums.begin(), nums.end(), dig) - nums.begin();

        if (idx < n) {
            res.push_back('0' + nums[idx]);
            if (nums[idx] > dig) {
                while ((int)res.size() < (int)a.size()) res.push_back('0' + mi);
                return res;
            }
        } else {
            while (!res.empty()) {
                int last = res.back() - '0';
                res.pop_back();

                int idx2 = upper_bound(nums.begin(), nums.end(), last) - nums.begin();
                if (idx2 < n) {
                    res.push_back('0' + nums[idx2]);
                    while ((int)res.size() < (int)a.size()) res.push_back('0' + mi);
                    return res;
                }
            }
            // Necesitamos más dígitos
            if (mi == 0) {
                int idx0 = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
                if (idx0 < n) {
                    res.push_back('0' + nums[idx0]);
                    while ((int)res.size() < (int)a.size() + 1) res.push_back('0' + mi);
                    return res;
                }
                return "";
            }
            return string(a.size() + 1, '0' + mi);
        }
    }
    return res;
}

void solve() {
    cin >> a >> n;
    nums = vi(n); cin >> nums;
    
    k = to_string(a);
    
    string b1 = mayorMenorIgual(k);
    string b2 = menorMayorIgual(k);
    
    ll o = LLONG_MAX;
    if (!b1.empty()) o = min(o, abs(a - stoll(b1)));
    if (!b2.empty()) o = min(o, abs(a - stoll(b2)));
    cout << o << el;
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
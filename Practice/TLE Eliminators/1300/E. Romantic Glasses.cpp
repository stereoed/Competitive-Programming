#pragma GCC optimize("Ofast")
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = a; i < (int)(n); i++)
#define pb push_back
#define all(v) v.begin(), v.end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int LIM = 1000000;
vector<uint32_t> es_primo(LIM + 1, true);
vector<int> primos;

void solve() {
    int n; cin >> n;
    vector<ll> v(n+1, 0);
    repx(i, 1, n+1){
        cin >> v[i];
        v[i] = v[i] * ((i%2) ? 1 : -1) + v[i-1];
    }

    sort(all(v));

    ll last = -INFINITY;
    rep(i, n+1){
        if (v[i] == last){
            cout << "YES" << el;
            return;
        }
        last = v[i];
    }

    cout << "NO" << el;
}
 
int main() {
    FastIO;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
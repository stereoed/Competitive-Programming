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
 
#define FastIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<pair<ll, int>, null_type,less<pair<ll, int>>, rb_tree_tag,tree_order_statistics_node_update>

int n;

int main() {
	FastIO;
	std::cin >> n;
	
	ordered_set s;
	for (int i = 0; i < n; i++){
		int a; std::cin >> a;
		s.insert({i, a});
	}
	
	for (int i = 0; i < n; i++){
		int a; std::cin >> a; a--;
		auto p = s.find_by_order(a);
		std::cout << p->second << " ";
		s.erase(*p);
	}
	std::cout << std::endl;
}
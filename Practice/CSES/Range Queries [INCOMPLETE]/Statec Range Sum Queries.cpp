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

const int MAXN = 2 * 1e5 + 5;
int n, k, a, b;
long long arr[MAXN];

int main() {
	FastIO;
	std::cin >> n >> k;
	arr[0] = 0;
	
	for (int i = 1; i <= n; i++){
		std::cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	
	for (int i = 0; i < k; i++){
		std::cin >> a >> b; a--;
		std::cout << arr[b] - arr[a] << std::endl;
	}
}
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

const int MAXN = 2 * 1e5, K = 20;
const int INF = 1e9;

int n, k, L, R;
int arr[K][MAXN];

int log2_floor(unsigned long i) {
	/*
	* Old, slower approach [O(log n)]
    * for (int len = 1; len <= 30; len++){
    *     long long test = ~((1 << len) - 1);
    *     if ((i & test) == 0) return len - 1;
    * }
    * return -1;
	*/
	return std::bit_width(i) - 1; // O(1)
}

int main() {
	FastIO;
	std::cin >> n >> k;
	
	// El primer nivel es para largo 1.
	for (int i = 0; i < MAXN; i++) arr[0][i] = INF;
	for (int i = 0; i < n; i++) std::cin >> arr[0][i];
	
	for (int i = 1; i < K; i++){
		for (int left = 0; left + (1 << i) - 1 < MAXN; left++){
			int right = left + (1 << (i - 1));
			arr[i][left] = std::min(arr[i-1][left], arr[i-1][right]);	
		}
	}
	
	for (int i = 0; i < k; i++){
		std::cin >> L >> R; L--; R--;
		int mK = log2_floor(R - L + 1); // Log 2 of distance
		
		std::cout << std::min(arr[mK][L], arr[mK][R - (1 << mK) + 1]) << std::endl;
	}
}
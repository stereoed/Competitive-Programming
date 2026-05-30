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

const int MAXN = 1001;
int mat[MAXN][MAXN];

int n, q;
char c;
int y1Q, x1Q, y2Q, x2Q;

int main() {
	FastIO;
	std::cin >> n >> q;
	
	std::memset(mat, 0, sizeof(mat));
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			std::cin >> c;
			mat[i][j] = mat[i][j - 1] + (c == '*');
		}
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			mat[i][j] += mat[i - 1][j];
		}
	}
	
	dump(mat);
	
	for (int i = 0; i < q; i++){
		std::cin >> y1Q >> x1Q >> y2Q >> x2Q;
		dump(y1Q, x1Q, y2Q, x2Q)
		dump(mat[y2Q][x2Q], mat[y1Q - 1][x1Q - 1], mat[y1Q - 1][x2Q], mat[y2Q][x1Q - 1])
		std::cout << mat[y2Q][x2Q] + mat[y1Q - 1][x1Q - 1] - mat[y1Q - 1][x2Q] - mat[y2Q][x1Q - 1] << std::endl;
	}
}
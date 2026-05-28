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

const int MAXN = 8;
int start_row, start_col;

int board[MAXN][MAXN];
std::vector<std::pair<int, int>> adj[MAXN][MAXN];

std::pair<int, int> delta[] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool customComparison(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	int sz_a = 0, sz_b = 0;
	
	for (const auto& [nrow, ncol] : adj[a.first][a.second]){
		if (board[nrow][ncol] == -1) sz_a++;
	}
	
	for (const auto& [nrow, ncol] : adj[b.first][b.second]){
		if (board[nrow][ncol] == -1) sz_b++;
	}
	
	return sz_a < sz_b;
}


bool dfs(int row, int col, int pos){
	std::sort(adj[row][col].begin(), adj[row][col].end(), customComparison);
	
	if (pos == 65) return true;
	
	for (const auto& [nrow, ncol] : adj[row][col]){
		if (board[nrow][ncol] != -1) continue;
		
		board[nrow][ncol] = pos;
		if (dfs(nrow, ncol, pos + 1)) return true;
		board[nrow][ncol] = -1;
	}
	
	return false;
}

int main() {
	FastIO;
	std::cin >> start_col >> start_row; start_col--; start_row--;
	
	for (int row = 0; row < MAXN; row++){
		for (int col = 0; col < MAXN; col++){
			board[row][col] = -1;
			
			for (const auto& [drow, dcol] : delta){
				int nrow = row + drow;
				int ncol = col + dcol;
				
				if (nrow < 0 || ncol < 0 || nrow >= MAXN || ncol >= MAXN) continue;
				
				adj[row][col].push_back({nrow, ncol});
			}
		}
	}
	
	board[start_row][start_col] = 1;
	dfs(start_row, start_col, 2);
	
	for (int row = 0; row < MAXN; row++){
		for (int col = 0; col < MAXN; col++){
			std::cout << board[row][col] << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}
#pragma GCC optimize("Ofast")
using namespace std;

#if __has_include("stdc++.h")
    #include "stdc++.h"
    #else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
    #else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define el '\n'


int n;
void solve() {
    cin >> n;
    vector<int> prev(n), next(n);
    vector<int> open_before;

    for (int i = 0; i < n; i++){
        cin >> prev[i] >> next[i];
        prev[i]--; next[i]--;

        if (prev[i] == -1) open_before.push_back(i);
    }

    dump(prev);
    dump(next);
    
    dump(open_before)

    int ptr_forward = 0, ptr_backward = 0;

    while (next[ptr_forward] != -1) ptr_forward = next[ptr_forward];
    while (prev[ptr_backward] != -1) ptr_backward = prev[ptr_backward];

    for (auto nxt : open_before){
        if (nxt == ptr_backward) continue;

        next[ptr_forward] = nxt;
        prev[nxt] = ptr_forward;

        while (next[ptr_forward] != -1) ptr_forward = next[ptr_forward];
    }

    dump(prev);
    dump(next);

    for (int i = 0; i < n; i++){
        cout << 1 + prev[i] << " " << 1 + next[i]  << el;
    }
}

int main() {
	FastIO;
    
	int t = 1;
	//cin >> t;
	
	while (t--) solve();
}
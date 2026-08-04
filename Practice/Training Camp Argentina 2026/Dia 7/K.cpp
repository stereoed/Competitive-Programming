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
#define repf(i,k,n) for(int i=k; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define el '\n'

long long n, k;

void solve(){
    cin >> n >> k; dump(n, k)
	vector<int> nums(n); rep(i,n) cin >> nums[i];
	vector<int> seg; 
    
    int segment_len = 0, winter = 0, changes = (nums[0] < 0);
    bool in_winter = false;

	rep(i,n) {
        bool is_winter = (nums[i] < 0);
        if (i > 0 && (nums[i] < 0) != (nums[i-1] < 0)) changes++;

        if (is_winter){
            winter++;
            if (in_winter) continue;

            in_winter = true;

            seg.push_back(segment_len);
            segment_len = 0;
        }

        else {
            in_winter = false;
            segment_len++;
        }
    }

    dump(changes, winter)

	if (winter > k){
		cout << -1 << endl;
		return;
	}

    if (winter == 0){
        cout << 0 << endl;
        return;
    }

    k -= winter;
    dump(k, changes, segment_len)

    seg[0] = 1e9;
	sort(all(seg));
    dump(seg);

    for (const auto x : seg){
        dump(k, x, changes)
        if (k < x) break;
        k -= x;
        changes -= 2;
    }

    dump(k, changes, segment_len)
    if(k >= segment_len && segment_len>0) changes--;

	cout << changes << endl;
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}
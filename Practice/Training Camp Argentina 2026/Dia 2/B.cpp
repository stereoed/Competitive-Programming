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
vector<int> hand, deck;

bool ok(int mid){
    vector<bool> have(n + 1);
    for (const int card : hand) if (card != 0) have[card] = true;
    for (int i = 0; i < mid; i++) if (deck[i] != 0) have[deck[i]] = true;

    int next = 1;
    for (int i = mid; i < n; i++){
        if (have[next++]) have[deck[i]] = true;
        else return false;
    }

    return true;
}

void solve() {
    cin >> n;
    hand = vector<int>(n);
    deck = vector<int>(n);

    for (auto& x : hand) cin >> x;
    for (auto& x : deck) cin >> x;

    int next = 1;
    for (int i = 0; i < n; i++){
        if (deck[i] == next) next += 1;
        else next = 1;
    }
    dump(next)

    if (next != 1){
        int temp_ans = n - next + 1;
        dump(temp_ans)

        vector<bool> have(n + 1);
        for (const int card : hand) if (card != 0) have[card] = true;

        int need = next;
        for (int i = 0; i < n - need + 1; i++){
            dump(have)
            dump(i, have[next], deck[i]);

            if (!have[next]){
                next = -1;
                break;
            }

            next++;
            have[deck[i]] = true;
        }

        dump(next, next >= n)
        if (next >= n){
            cout << temp_ans << el;
            return;
        }
    }

    int l = 0, r = n;
    while (l < r){
        int mid = l + (r - l) / 2;
        if (ok(mid)) r = mid;
        else l = mid + 1;
    }

    cout << n + l << el;
}

int main() {
    FastIO;
    solve();
}
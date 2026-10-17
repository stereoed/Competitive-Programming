#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long k1, k2;
    cin >> k1 >> k2;
    long long k3 = k1 + k2;

    vector<long long> a(n), b(n), c(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (int i = 0; i < n; i++) c[i] = llabs(a[i] - b[i]);

    sort(c.rbegin(), c.rend());
    c.push_back(0); // sentinel so c[i+1] is always defined

    long long ans = 0;
    bool finished_early = false;

    for (int i = 0; i < n; i++) {
        long long groupSize = i + 1;
        long long dif = groupSize * (c[i] - c[i + 1]); // cost to bring the top group down to the next level

        if (k3 > dif) {
            k3 -= dif;
            continue; // fully paid, move to the next level
        }

        // not enough left to finish this transition: spend remaining k3
        // evenly across the groupSize tied elements
        long long q = k3 / groupSize;
        long long rem = k3 % groupSize;
        long long newVal = c[i] - q;

        // rem elements take one extra decrement (newVal-1), the rest stay at newVal
        ans += rem * (newVal - 1) * (newVal - 1) + (groupSize - rem) * newVal * newVal;

        for (int j = i + 1; j < n; j++) ans += c[j] * c[j]; // untouched, still original

        finished_early = true;
        break;
    }

    if (!finished_early) {
        // whole array driven to 0 with budget to spare; leftover ops cancel in
        // pairs, one unpaired leftover forces a final +-1 on some element
        if (k3 % 2 == 1) ans += 1;
    }

    cout << ans << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
struct node{
    int val = -1;
    node* prev = nullptr;
    node* next = nullptr;
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n; 
    cin >> n;
 
    vector<node> arr(n);
    for (int i = 0; i < n; i++) arr[i].val = i + 1;
 
    for (int i = 0; i < n; i++) {
        arr[i].prev = &arr[(i - 1 + n) % n];
        arr[i].next = &arr[(i + 1) % n];
    }
 
    node* cur = &arr[0];  // current survivor pointer
    int alive = n;
 
    while (alive > 1) {
        node* del = cur->next;          // remove every 2nd person
        cout << del->val << " ";
 
        del->prev->next = del->next;    // unlink del
        del->next->prev = del->prev;
 
        cur = del->next;                // next survivor after deleted one
        alive--;
    }
 
    cout << cur->val << "\n";           // last remaining (optional; remove if not wanted)
    return 0;
}
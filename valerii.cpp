#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(vector<ll> arr) {
    unordered_set<ll> store;
    for (int i = 0; i < arr.size(); i++) {
        if (store.find(arr[i]) == store.end()) {
            store.insert(arr[i]);
        }
        else {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr);
    }
    return 0;
}

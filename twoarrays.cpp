#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll arr[100000];
ll arr_duplicate[100000];

void solve(ll n, ll arr[], ll arr_duplicate[], ll T) {
    unordered_set<ll> one;
    unordered_set<ll> zero;
    vector<ll> ans(n, 0);
    ll counter = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] * 2 == T) {
            counter++;
        }
    }
    ll count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] * 2 == T && count < counter/2) {
            ans[i] = 1;
            count++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] * 2 != T) {
            if (one.find(T - arr[i]) == one.end()) {
                ans[i] = 1;
                one.insert(arr[i]);
            }
            else {
                arr[i] = 0;
                zero.insert(arr[i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }   
    cout << '\n';
    return;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, T;
        cin >> n >> T;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr_duplicate[i] = arr[i];
        }
        solve(n, arr, arr_duplicate, T);
    }
}

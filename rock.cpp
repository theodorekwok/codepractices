#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll arr[100000];


void solve(ll arr[], int n) {
    ll bit[32] = {0};
    for (int i = 0; i < n; i++) {
        int k = (int) log2(arr[i]) + 1;
        bit[k]++;
    }
    ll ans = 0;
    for (int i = 0; i < 32; i++) {
        ans += (bit[i])*(bit[i] - 1)/2;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr, n);

    }
}

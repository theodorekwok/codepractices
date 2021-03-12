#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll arr[100000];

void solve(int n, ll arr[]) {
    ll ans = -1e18;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        ll p = 1;
        for (int j = i; j < i + 5; j++) {
            if (j >= n) {
                p *= arr[j - n];
            }
            else {
                p *= arr[j];
            }   
        }
        if (p > ans) {
            ans = p;
       }
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
        solve(n, arr);
    }

}

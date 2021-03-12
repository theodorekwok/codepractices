#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll arr[300000];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll ans = arr[0];
        ll max = arr[0];
        ll drop = 0;
        bool dropped = false;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                if (dropped) {
                    ans = drop;
                    ans += arr[i - 1];
                    dropped = false;
                }
                ans += arr[i] - arr[i - 1];
            }
            else {
                dropped = true;
                drop += arr[i - 1] - arr[i];
            }

            if (ans > max) {
                max = ans;
            }
        }
        cout << max << '\n';
    }
}

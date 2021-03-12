#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        // get number of distinct values
        int dis = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) {
                dis++;
            }
        }
        // cout << dis << '\n';
        if (k == 1 && dis > 1) {
            cout << -1 << '\n';
            continue;
        }
        if (k >= dis) {
            cout << 1 << '\n';
        }
        else {
            int ans = 1;
            ans += (dis - k) % (k  - 1) == 0 ? (dis - k)/(k - 1) : (dis - k)/(k - 1) + 1;
            cout << ans << '\n';
        }
    }
    
}

#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>> arr, int k) {

    for (int i = 0; i < arr.size(); i++) {
        int same_region = 0;
        for (int j = 0; j < arr.size(); j++) {
            if (i != j) {
                int distance = abs(arr[i][0] - arr[j][0]) + abs(arr[i][1] - arr[j][1]);
                if (distance <= k) {
                    same_region++;
                }
            }
            if (same_region == arr.size() - 1) {
                cout << 1 << '\n';
                return;
            }
        }   
    }
    cout << -1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        solve(arr, k);
    }    
    return 0;

}

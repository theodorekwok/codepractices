#include <bits/stdc++.h>

using namespace std;

int arr[1000];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int i = 0;
        int k = 0;
        vector<int> ans;
        while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                k += 2;
                ans.push_back(arr[i]);
                ans.push_back(arr[i + 1]);
                i += 2;
                continue;
            }
            else {
                if (i + 2 <= n - 1) {
                    ans.push_back(arr[i + 2]);
                    ans.push_back(arr[i + 2]);
                    k += 2;
                    i += 3;
                }
                else {
                    ans.push_back(0);
                    k++;
                    i += 2;
                }
            }
        }
        cout << k << '\n';
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n'; 
    }
}

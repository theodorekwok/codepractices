#include <bits/stdc++.h>

using namespace std;

int arr[1000];

void solve(int arr[], int n, int s[]) {
    vector<int> ans;
    int* max = max_element(arr, arr + n);
    ans.push_back(*max);
    s[*max]--;
    int size = n - 1;
    int curr_gcd = *max;
    while (size) {
        int m = 0;
        int val = 0;
        bool present = false;
        for (int i = 0; i < n; i++) {
            if (s[arr[i]]) {
                int g = __gcd(ans[0], arr[i]);
                int sg = __gcd(g, curr_gcd); 
                // cout << arr[i] << ' ' << g << ' ' << sg << '\n';
                if (sg > m) {   
                    m = sg;
                    val = arr[i];
                    present = true;
                    // cout << arr[i] << ' ' << g << ' ' << sg << ' ' << m << '\n';
                }
            }
        }
        if (present) {
            curr_gcd = m;
            s[val]--;
            ans.push_back(val);
        }
        size--;
    }
    for (int i = 1; i <= 1000; i++) {
        while (s[i]) {
            ans.push_back(i);
            s[i]--;
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s[1001] = {0};
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            s[arr[i]]++;
        }
        solve(arr, n, s);
    }
    return 0;

}

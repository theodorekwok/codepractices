#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &a, vector<int> &ans, int d, int l, int r) {
    //cout << l << ' ' << r << ' ' << d << '\n';
    if (l >= r) {
        if (l == r) ans[l] = d;
        return;
    }
    
    // find max
    int max = a[l];
    int index = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] > max) {
            max = a[i];
            index = i;
        }
    }
    ans[index] = d;
    // go left 
    solve(a, ans, d + 1, l, index - 1);
    // go right
    solve(a, ans, d + 1, index + 1, r);

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> a(100);
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int d = 0;
        int l = 0;
        int r = n - 1;
        vector<int> ans(n, 0);
        solve(a, ans, d, l, r);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}


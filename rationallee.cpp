#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[200000] = {0};
ll w[200000] = {0};

void solve(ll a[], ll w[], int n, int k) {
    sort(a, a + n);
    sort(w, w + k);
    // index 1 is the max, index 0 is the minimum
    vector<vector<ll>> ans(k);
    //cout << k << '\n';
    int index = n - 1;
    int i = 0;
    while (w[i] == 1 && i < k) {
        ans[i] = {a[index], a[index]};
        index--;
        i++;
    }
    for (int j = i; j < k; j++) {
        ans[j] = {0, a[index]};
        index--;
    }
    
    int indexa = 0;
    int indexw = k - 1;
    while (indexw >= 0) {
        if (w[indexw] == 1) {
            indexw--;
        }
        else {
            ans[indexw][0] = a[indexa];
            indexa += w[indexw] - 1;
            indexw--;
        }
    }
    ll sum = 0;
    for (int i = 0 ; i < ans.size(); i++) {
        sum += ans[i][0] + ans[i][1];
        //cout << ans[i][0] << ' ' << ans[i][1] << '\n';
    }
    cout << sum << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> w[i];
        }   
        
        solve(a, w, n, k);
    }
}

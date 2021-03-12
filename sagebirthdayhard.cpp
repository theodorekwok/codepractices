#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[100000];
ll c[100000];



void solve(ll a[], ll c[], int n) {
    if (n <= 2) {
        cout << 0 << '\n';
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    vector<ll> ans;
    /*int ind = 0;
    for (int i = 1; i < n; i+=2) {
        ans[i] = c[ind];
        ind++;
    }
    for (int i = 0; i < n; i+=2) {
        ans[i] = c[ind];
        ind++;
    }*/
    int b = n/2;
    int f = 0;
    while (f < n/2) {
        ans.push_back(c[b]);
        ans.push_back(c[f]);
        b++;
        f++;
    }
    if (n % 2 != 0) {
        ans.push_back(c[b]);
    }

    int m = 0;
    for (int i = 1; i < n - 1; i++) {
        if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) {
            m++;
    
        }
    }
    cout << m << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[i] = a[i];
    }
    sort(c, c + n);
    solve(a, c, n);
}

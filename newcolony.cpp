#include <bits/stdc++.h>

#define ll long long

using namespace std;

int a[100];


void solve(int *a, int n, int k) {
    if (k == 1) {
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < a[i+1]) {
                a[i]++;
                cout << i + 1 << '\n';
                return;
            }
        }
        cout << -1 << '\n';
        return;
    }
    // cout << "k " << k << '\n';
    bool slope = false;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i+1]) {
            a[i]++;
            slope = true;
            break;
        }
    }
    if (!slope) {
        //cout << k << '\n';
        /*for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }*/
        cout << -1 << '\n';
        return;
    }
    solve(a, n, k - 1);
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        
        int m = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > m) m = a[i];
        }
        int boulders = 0;
        for (int i = 0; i < n; i++) {
            boulders += m - a[i];
        }
        if (k > boulders) {
            cout << -1 << '\n';
        }
        else {
            solve(a, n, k);
        }
    }
}

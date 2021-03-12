#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[300][300];


void solve(ll a[][300], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int d[4] = {i - 1, j - 1, j + 1, i + 1};
            int out = 0;
            for (int v = 0; v < 4; v++) {
                if (d[v] < 0 || (d[v] == n && v == 3) || (d[v] == m && v == 2))
                    out++;
            }
            if (a[i][j] > 4 - out) {
                cout << "NO" << '\n';
                return;
            }

            a[i][j] = 4 - out;
        }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        solve(a, n, m);
    }
}



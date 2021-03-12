#include <bits/stdc++.h>

#define ll long long

ll arr[100][100];

using namespace std;


void solve(int n, int m, ll arr[][100]) {
    int height = (n % 2 == 0) ? n/2 : n/2 + 1;
    int width = (m % 2 == 0) ? m/2 : m/2 + 1;
    ll ans = 0;
    ll copy[100][100];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ll one = arr[i][j];
            ll two = arr[i][m - j - 1];
            ll three = arr[n - i - 1][j];
            ll four = arr[n - i - 1][m - j - 1];
            ll temp[] = {one, two, three, four};
            sort(temp, temp + 4);
            copy[i][j] = temp[1];
            copy[i][m - j - 1] = temp[1];
            copy[n - i - 1][j] = temp[1];
            copy[n - i - 1][m - j - 1] = temp[1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += abs(arr[i][j] - copy[i][j]);
        }
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        solve(n, m, arr);
    }
}

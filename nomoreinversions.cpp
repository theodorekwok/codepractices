#include <bits/stdc++.h>

using namespace std;

int a[100000];

void solve(int n, int k) {
    for (int i = 0; i < k; i++) {
        a[i] = i + 1;
    }
    sort(a + (k - (n - k)) - 1, a + k, greater<int>());
    for (int i = 0; i < k; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        solve(n, k);
    }
}

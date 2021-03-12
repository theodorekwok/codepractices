#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    int remainder = n % 2020;
    int factor = n / 2020;

    if (factor >= remainder) {
       cout << "YES" << '\n';
        return;
    }
    

    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
}




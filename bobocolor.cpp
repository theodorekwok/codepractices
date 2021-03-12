#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(ll a[]) {
    int odd = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] % 2 != 0) odd++;
    }
    int odd_two = -1;
    if (a[0] && a[1] && a[2]) {
        odd_two = 4 - odd;
    }
    if (odd_two == -1) {
        if (odd == 0 || odd == 1) {
            cout << "Yes" << '\n';
            return;
        }
        cout << "No" << '\n';
        return;
    }
    if (odd == 0 || odd == 1 || odd_two == 0 || odd_two == 1) {
        cout << "Yes" << '\n';
        return;
    }
    cout << "No" << '\n';
    return;

} 

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a[4];
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        solve(a); 
    }
}


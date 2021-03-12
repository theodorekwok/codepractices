#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(int n, int x, int y) {
    int interval = n - 1;
    if ((y - x) % interval == 0) {
        int temp = x;
        for (int i = 0; i < n; i++) {
            cout << temp << ' ';
            temp += (y - x)/interval;
        }
        cout << '\n';
        return;
    }

    // not divisible so must find the appropriate difference
    while ((y - x) % interval != 0) {
        interval--;
    }
    int diff = (y - x)/interval;
    int smallest = x;
    int behind = 0;
    while (smallest - diff > 0 && behind < n - (interval + 1)) {
        smallest -= diff;
        behind++;
    }
    for (int i = 0; i < n; i++) {
        cout << smallest << ' ';
        smallest += diff;
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        solve(n, x, y);
    }
}

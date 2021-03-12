#include <bits/stdc++.h>

using namespace std;

int a[1000];

void solve(int a[], int n, int x) {
    int changes = 0;
    bool allsame = true;
    bool infect = false;
    for (int i = 0; i < n; i++) {
        changes += x - a[i];
        if (x != a[i]) {
            allsame = false;
        }
        else {
            infect = true;
        }
    }
    if (changes == 0 && allsame) {
        cout << 0 << '\n';
        return;
    }
    else if ((changes == 0 && !allsame) || infect ) {
        cout << 1 << '\n';
        return;
    }

    cout << 2 << '\n';
    return;
    


}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a, n, x);
    }
}

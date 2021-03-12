#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[10000];


void solve(ll a[], int q, int d) {
    int cycle = 1;
    int digit = d;
    do {
        digit += d;
        cycle++;
    } while (digit % 10 != d);

    for (int i = 0; i < q; i++) {
        ll v = a[i];
        if (v >= 10*d) {
            cout << "YES" << '\n';
        }
        else {
            //cout << v << '\n';
            bool have = false;
            for (int i = 1; i <= cycle; i++) {
                if ((d*i) % 10 == v % 10) {
                    if (d*i <= v) {
                        cout << "YES" << '\n';
                    }
                    else {
                        cout << "NO" << '\n';
                    }
                    have = true;
                    break;
                }
            }
            if (!have) {
                cout << "NO" << '\n';
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q, d;
        cin >> q >> d;
        for (int i = 0; i < q; i++) {
            cin >> a[i];
        }

        solve(a, q, d);
    }
}

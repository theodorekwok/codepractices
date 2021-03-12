#include <bits/stdc++.h>

using namespace std;

void solve(int a, int b, int c, int d) {
    int net = a + b;
    string as, bs, cs, ds;
    // net pos
    if (net % 2 == 0) {
        as = "Tidak";
        bs = "Tidak";
        if (a != 0 || d != 0) {
            ds = "Ya";
        }
        else {
            ds = "Tidak";
        }

        if (c != 0 || b != 0) {
            cs = "Ya";
        }
        else {
            cs = "Tidak";
        }
    }
    else {
        cs = "Tidak";
        ds = "Tidak";
        if (a != 0 || d != 0) {
            as = "Ya";
        }
        else {
            as = "Tidak";
        }

        if (c != 0 || b != 0) {
            bs = "Ya";
        }
        else {
            bs = "Tidak";
        }
    }
    cout << as << ' ' << bs << ' ' << cs << ' ' << ds << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        solve(a, b, c, d);
    }
}

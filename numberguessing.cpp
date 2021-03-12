#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, n;
        cin >> a >> b >> n;
        while (true) {
            ll mid = (a + b)/2;
            cout << mid << '\n';
            fflush(stdout);
            string r;
            cin >> r;
            if (r == "TOO_BIG") {
                b = mid - 1;
            }
            else if (r == "TOO_SMALL") {
                a = mid + 1;
            }
            else {
                break;
            }

        }
    }
}

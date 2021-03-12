#include <bits/stdc++.h>

#define ll long long

ll b[100000];
ll d[100000];

using namespace std;

void solve(int n, ll b[], ll d[]) {
    sort(b, b + n);
    sort(d, d + n);
    ll max = 0;
    ll curr = 0;
    ll year = b[0];
    int d_index = 0;
    for (int i = 0; i < n; i++) {
        curr++;
        if (b[i] >= d[d_index]) {
            curr--;
            d_index++;
        }
        if (curr > max) {
            max = curr;
            year = b[i];
        }
    }
    cout << year << ' ' << max << '\n';
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i] >> d[i];
    }
    solve(n, b, d);

}

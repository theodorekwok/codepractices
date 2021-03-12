#include <bits/stdc++.h>

#define ll long long

using namespace std;

int a[100000];

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = a[i];
    }
    int max = a[0];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == i + 1 && a[i] >= max) {
            ans++;
            max = a[i];
        }
        else {
            if (a[i] > max) {
                max = a[i];
            }
        }
    }
    cout << ans << '\n';
}

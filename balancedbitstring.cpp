#include <bits/stdc++.h>

using namespace std;




void solve(string s, int n, int k) {
    for (int i = 0; i < k; i++) {
        if (s[i] == '?') {
            for (int j = i + k; j < n; j+=k) {
                if (s[j] != '?') {
                    s[i] = s[j];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < k; i++) {
        if (s[i] != '?') {
            for (int j = i + k; j < n; j += k) {
                if (s[j] == '?') {
                    s[j] = s[i];
                }
                else if (s[i] != s[j]) {
                    cout << "NO" << '\n';
                    return;
                }   
            }
        }   
    }
    int zero = 0;
    int one = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == '1') one++;
        else if (s[i] == '0') zero++;
    }
    if (zero > k/2 || one > k/2) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        solve(s, n, k);
    }
}

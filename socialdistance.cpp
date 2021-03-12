#include <bits/stdc++.h>

using namespace std;


void solve(string s, int n, int k) {
    vector<int> sb;
    int i = 0;
    while (i < n) {
        if (s[i] == '0') {
            sb.push_back(i);
            while (i < n && s[i] == '0') {
                i++;
            }   
            sb.push_back(i);
        }
        else {
            i++;
        }
    }
    int ans = 0;
    for (int i = 0; i < sb.size(); i += 2) {
        int gap = sb[i+1] - sb[i];
        // cout << sb[i+1] << ' ' << sb[i] << '\n';
        if ((sb[i] == 0 && sb[i+1] != n) || (sb[i] != 0 && sb[i+1] == n)) {
            gap -= k;
        }
        else if (sb[i] != 0 && sb[i+1] != n) {
            gap -= 2*k;
        }
        if (gap >= 0) {
            ans += gap/(k+1);
            ans += (gap%(k+1) == 0) ? 0 : 1;
        }
    }
    cout << ans << '\n';

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

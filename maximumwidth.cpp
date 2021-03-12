#include <bits/stdc++.h>

using namespace std;


void solve(string s, string t, int n, int m) {
    int index = 0;
    vector<int> l(m);
    vector<int> r(m);
    for (int i = 0; i < n; i++) {
        if (s[i] == t[index]) {
            l[index] = i;
            index++;
        }
    }
    int ind = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == t[ind]) {
            r[ind] = i;
            ind--;
        }
    }
    /*for (int i = 0; i < l.size(); i++) {
        cout << l[i] << ' ' << r[i] << '\n';
    }*/
    int ans = 0;
    for (int i = 0; i < m - 1; i++) {
        ans = max(ans, r[i + 1] - l[i]);
    }
    cout << ans << '\n';
}


int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    
    solve(s, t, n, m);

}

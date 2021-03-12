#include <bits/stdc++.h>

using namespace std;

void solve(string s) {
    int cw = 0; 
    int acw = 0;
    int bidirectional = 0;
    int yes = 0;
    if (s[0] == '-' || s[s.size() - 1] == '-') {
        yes++;
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == '-' || s[i] == '-') {
            yes++;
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            bidirectional++;
        }   
        if (s[i] == '>') {
            cw++;
        }
        if (s[i] == '<') {
            acw++;
        }
    }
    if (cw == 0 || acw == 0 || bidirectional == s.size() || cw == s.size() || acw == s.size()) {
        cout << s.size() << '\n';
        return;
    }

    cout << yes << '\n';


}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}

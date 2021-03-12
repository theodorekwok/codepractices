#include <bits/stdc++.h>

using namespace std;

void solve(string s) {
    int counter = 0;
    string preferred = "1";
    string preferred_two = "0";
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '1' && s[i - 1] == '1') {
            counter += 1;
        }
        if (i % 2 != 0) {
            preferred.push_back('0');
            preferred_two.push_back('1');
        }
        else {
            preferred.push_back('1');
            preferred_two.push_back('0');
        }

    }
    if (counter != 0) {
        if (s[s.size() - 1] == '1' && s[0] == '1') {
            counter++;
        }
        cout << counter << '\n';
        return;
    }
    if (s == preferred || s == preferred_two) {
        cout << 0 << '\n';
        return;
    }
    cout << 1 << '\n';
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

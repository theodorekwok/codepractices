#include <bits/stdc++.h>


using namespace std;

bool check(string s) {
    if (s.size() % 2 != 0 || s[0] == ')' || s[s.size() - 1] == '(') {
        return false;
    }

    return true;



}


int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool can = check(s);
        if (can) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;

}

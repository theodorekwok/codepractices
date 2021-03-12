#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int back = 0;
        int i = n - 1;
        while (i >= 0 && s[i] == '1') {
            back++;
            i--;
        }
        int front = 0;
        int index = 0;
        while (s[index] == '0') {
            front++;
            index++;
        }
        int zero = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zero++;
        }
        for (int i = 0; i < front; i++) {
            cout << '0';
        }
        if (zero != front) cout << '0';

        for (int i = 0; i < back; i++) {
            cout << '1';
        }
        cout << '\n';
    }
}

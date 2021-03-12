#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll a[1000000];


int main() {
    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll length = s.size();
        ll res = 0;
        int curr = 0;
        for (int i = 0; i < length; i++) {
            if (s[i] == '+') curr++;
            else curr--;
            a[i] = curr;
        }
        vector<int> c(length, 0);
        for (int i = 0; i < length; i++) {
            if (-1 - a[i] >= 0) {
                if (c[-1 - a[i]] == 0) {
                    res += i + 1;
                    c[-1 - a[i]] = 1;
                }
            }   
        }   
        res += length;
        cout << res << '\n';
    }
}

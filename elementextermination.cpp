#include <bits/stdc++.h>

using namespace std;

int a[300000];

void solve(int a[], int n) {
    /*stack<int> s;
    for (int i = 0; i < n; i++) {
        if (s.empty()) 
            s.push(a[i]);
        "else {
            int h = s.top();
            if (a[i] < h) {
                s.push(a[i]);
            }
            else {
                while (!s.empty() && a[i] > h) {
                    if (s.size() > 1) {
                        s.pop();
                        h = s.top();
                    }
                    else {
                        break;     
                    }
                }
                if (s.top() > a[i]) {
                    s.push(a[i]);
                }               
            }
        }
    }*/
    if (a[0] < a[n - 1]) cout << "YES" << '\n';//(s.size() == 1) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a, n);
    }
}

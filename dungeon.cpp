#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a;
        int b;
        int c;
        cin >> a >> b >> c;
        int sum = a + b + c;
        if (sum % 9 == 0) {
            int factor = sum/9;
            if (a < factor || b < factor || c < factor) {
                cout << "NO" << '\n';
            }
            else {
                cout << "YES" << '\n';
            }   
        }
        else {
            cout << "NO" << '\n';
        }

    }   
    return 0;
}

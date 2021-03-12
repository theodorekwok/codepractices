#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    cout << 2 << '\n';
    int val = n;
    int second_val = n - 1;
    for (int i = 0; i < n - 1; i++) {
        cout << val << ' ' << second_val << '\n';
        if ((val + second_val) % 2 != 0) {
            val = (val + second_val)/2;
            val++;
        }
        else {
            val = (val + second_val)/2;
        }   
        second_val--;
    }
}

    
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}

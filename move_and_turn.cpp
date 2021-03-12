#include <bits/stdc++.h>

using namespace std;


long possible(int n) {
    if (n == 1) {
        return 4;
    }    
    if (n % 2 == 0) {
        long base = n - (n - 2)/2;
        return base * base;
    }
    if (n == 3) {
        return 12;
    }
    long add = 12;
    long ans = 12;
    for (int i = 5; i <= n; i += 2) {
        ans += add;
        add += 4;
    }

    return ans;

}


int main() {
    int n;
    cin >> n;
    long num_locations = possible(n);
    cout << num_locations << '\n';
    return 0;
}

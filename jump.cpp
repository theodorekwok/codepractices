#include <bits/stdc++.h>

using namespace std;

int min(int x) {
    int root =ceil((-1 + sqrt(1 + 4*2*x))/2);
    int steps = root*(root + 1)/2;
    if (steps == x) {
        return root;
    } 
    int diff = steps - x;
    if (diff == 1) {
        return root + 1;
    }
    return root;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int min_jumps = min(x);
        cout << min_jumps << '\n';
    }
}

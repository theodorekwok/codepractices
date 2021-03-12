#include <bits/stdc++.h>

using namespace std;

void solve(string s) {
    cout << 3 << '\n';
    cout << 'L' << ' ' << 2 << '\n';
    cout << 'R' << ' ' << 2 << '\n';
    cout << 'R' << ' ' << (s.size() - 1)*2 + 1 << '\n';
}

int main() {
    string s;
    cin >> s;
    solve(s);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void solve(string s, int k) {
    vector<int> bounds;
    int index = 0;
    while (s[index] == 'L') {
        index++;
    }
    int front = index;
    int end_index = s.size() - 1;
    while (s[end_index] == 'L') {
        end_index--;
    }
    while (index < end_index) {
        int start = index;
        int end = index;
        while (s[end] == 'L') {
            end++;
        }

        if (end > start) {
            bounds.push_back(end - start);
        }
        index = end + 1;
    }

    sort(bounds.begin(), bounds.end());

    int ans = 0;
    for (int i = 0; i < bounds.size(); i++) {
        if (k >= bounds[i]) {
            ans += bounds[i]*2 + 1;
            k -= bounds[i];
        }
        else {
            ans += k*2;
            k = 0;
        }
    }
    
    int end_losses = s.size() - end_index - 1;
    int front_losses = front;
    if (front == s.size()) {
        if (k == 0) {
            cout << 0 << '\n';
            return;
        }
        cout << (k - 1)*2 + 1 << '\n';
        return;
    }


    if (k > 0) {
        if (front_losses + end_losses > k) {
            ans += k*2;
            k = 0;
        }
        else {
            cout << (s.size() - 1)*2 + 1 << '\n';
            return;
        }
    }

    if (s[0] == 'W') {
        ans += 1;
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'W') {
            if (s[i - 1] == 'W') {
                ans += 2;
            }
            else {
                ans += 1;
            }       
        }
    }
    cout << ans << '\n';


}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        solve(s, k);
    }
}

#include <bits/stdc++.h>

using namespace std;

void solve(string s) {

    stack<char> st;
    st.push(s[0]);
    int index = 1;
    while (index < s.size()) {
        if (st.empty()) {
            st.push(s[index]);
            index++;
            continue;
        }
        if (s[index] == 'B') {
            st.pop();
        }
        else {
            st.push(s[index]);
        }
        index++;
    }
    cout << st.size() << '\n'; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        solve(s);
    }
}

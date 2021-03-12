#include <bits/stdc++.h>


using namespace std;


int remove(string s) {
    int counter = 0;
    for (int i = 1; i < s.size(); i++) {
        if (i == 1) {
            if (s[i] == s[i - 1]) {
                s[i] = '1';
                counter++;
            }
        }
        else {
            if (s[i] == s[i - 1] || s[i] == s[i - 2]) {
                s[i] = '1';
                counter++;
            }
        }
    }
    return counter;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int min = remove(s);
        cout << min << '\n';
    }
    return 0;

}

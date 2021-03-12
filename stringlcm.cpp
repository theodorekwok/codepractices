#include <bits/stdc++.h>

using namespace std;


void LCM(string s1, string s2) {
    int multiple = 1;
    while (s1.size()*multiple % s2.size() != 0) {
        multiple++;
    }
    int length = s1.size()*multiple;
    string first = "";
    string second = "";
    for (int i = 0; i < multiple; i++) {
        first += s1;
    }
    for (int i = 0; i < length/s2.size(); i++) {
        second += s2;
    }

    for (int i = 0; i < first.size(); i++) {
        if (first[i] != second[i]) {
            cout << "-1" << '\n';
            return;
        }
    }
    cout << first << '\n';


}

int main() {
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        LCM(s1, s2);
    }

    return 0;
}

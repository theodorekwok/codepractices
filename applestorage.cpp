#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    map<int,int> lf; 
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        lf[a]++;
    }
    map<int,int> fl;
    for (auto itr = lf.begin(); itr != lf.end(); itr++) {
        fl[itr->second]++;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string symbol;
        int x;
        cin >> symbol >> x;
        if (symbol == "+") {
            lf[x]++;
            fl[lf[x]]++;
            fl[lf[x] - 1]--;
            if (fl[lf[x] - 1] == 0) {
                fl.erase(lf[x] - 1);
            }
        }
        else {
            lf[x]--;
            fl[lf[x]]++;
            fl[lf[x] + 1]--;
            if (fl[lf[x] + 1] == 0) {
                fl.erase(lf[x] + 1);
            }
        }
        int sum = 0;
        bool gotsquare = false;
        for (auto itr = fl.begin(); itr != fl.end(); itr++) {
            if (itr->first >= 2) {
                int factor = (itr->first % 2 == 0) ? itr->first : itr->first - 1;
                sum += factor*itr->second;
            }
            if (itr->first >= 4) {
                gotsquare = true;
            }
        }
        if (!gotsquare) {
            cout << "NO" << '\n';
        }
        else {
            sum -= 4;
            if (sum >= 4) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }

}

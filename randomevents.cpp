#include <bits/stdc++.h>

using namespace std;

int a[100001];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int mv = n;
        int index = n;
        while (a[index] == mv) {
            index--;
            mv--;
            if (index == 0) break;
        }
        double ans = 1.000000;
        for (int i = 0; i < m; i++) {
            int r;
            double p;
            cin >> r >> p;
            if (r >= index) {
                ans *= (1.0-p);
            }
        }
        ans = 1.000000 - ans;
        if (index == 0) printf("%.6f",1.0);
        else printf("%.6f",ans);
        cout << '\n';

    }
}

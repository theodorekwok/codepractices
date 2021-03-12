#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[100000];


void solve(ll a[], ll n, ll l) {
    int flag_front = 0;
    int flag_back = n - 1;
    int speed_front = 1;
    int speed_back = 1;
    double distfront = 0;
    double distback = 0;
    double t = 0;
    while (flag_front <= flag_back) {
        double tchangefront = (a[flag_front] - distfront)/speed_front;
        double tchangeback = (l - a[flag_back] - distback)/speed_back;
        if (tchangefront > tchangeback) {
            distback = l - a[flag_back];
            distfront += tchangeback * speed_front;
            flag_back--;
            speed_back++;
        }
        else if (tchangeback > tchangefront) {
            distfront = a[flag_front];
            distback += tchangefront * speed_back;
            flag_front++;
            speed_front++;
        }
        else if (abs(tchangeback - tchangefront) <= 0.00000000000001) {
            distback = l - a[flag_back];
            distfront = a[flag_front];
            flag_front++;
            flag_back--;
            speed_front++;
            speed_back++;
        }
        t += min(tchangefront, tchangeback);

    }
    /*if (l - abs(distfront + distback) <= 0.000000000000001) {
        printf("%0.15lf\n", t);
        return;
    }*/
    double textra = 0;
    double distleft = l - (distfront + distback);
    textra = distleft/(speed_front + speed_back);
    t += textra;
    printf("%0.15lf\n", t);
    return;

}


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, l;
        cin >> n >> l;
        for (int i = 0; i < n; i++) cin >> a[i];
        solve(a, n, l);
    }
}

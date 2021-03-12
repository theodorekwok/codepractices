#include <bits/stdc++.h>


using namespace std;


void get_arr(vector<long> arr) {
    unsigned long long sum = 0;
    unsigned long long half_sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (i % 2 == 0) {
            half_sum += arr[i];
        }
    }

    if (half_sum * 2 > sum) {
        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0) {
                cout << arr[i] << ' ';
            }
            else {
                cout << 1 << ' ';
            }
        }
    }
    else {
        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0) {
                cout << 1 << ' ';
            }
            else {
                cout << arr[i] << ' ';
            }
        }
    }


    cout << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; 
        }
        get_arr(arr);
    }

}

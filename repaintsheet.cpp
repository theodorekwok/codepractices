#include <bits/stdc++.h>


using namespace std;

int arr[100000];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }   
        int ans = INT_MAX;
        for (int i = 1; i <= 100; i++) {
            int index = 0;
            int temp = 0;
            while (index < n) {
                if (arr[index] == i) {
                    index++;
                }
                else {
                    temp += 1;
                    index += k;
                }
            }
            if (temp < ans) {
                ans = temp;
            }
        }
        cout << ans << '\n';
    }   
}

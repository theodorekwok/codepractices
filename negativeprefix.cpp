#include <bits/stdc++.h>

using namespace std;

int arr[100];
int l[100];

void solve(int n, int arr[], int l[], vector<int> pos, vector<int> neg) { 
    sort(pos.rbegin(), pos.rend());
    sort(neg.rbegin(), neg.rend());
    int pos_index = 0;
    int neg_index = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] == 0) {
            if (pos_index < pos.size()) {
                arr[i] = pos[pos_index];
                pos_index++;
            }
            else {
                if (neg_index < neg.size()) {
                    arr[i] = neg[neg_index];
                    neg_index++;
                }
            }       
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

}


int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> pos;
        vector<int> neg;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> l[i];
            if (l[i] == 0) {
                if (arr[i] >= 0) {
                    pos.push_back(arr[i]);
                }
                else {
                    neg.push_back(arr[i]);
                }
            }      
        }


        solve(n, arr, l, pos, neg);
    }
}


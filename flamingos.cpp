#include <bits/stdc++.h>

using namespace std;

int arr[1000];

int main() {
    int N;
    cin >> N;
    
    int size = N;
    int total;
    int index = N - 1;
    int L = 1;
    int R = N;
    cout << "? " << L << ' ' << R << '\n';
    fflush(stdout); 
    cin >> total;
    N -= 2;
    R--;
    while (N--) {
        cout << "? " << L << ' ' << R << '\n';
        fflush(stdout);
        int amount;
        cin >> amount;
        arr[index] = total - amount;
        total = amount;
        index--;
        R--;
    }
    cout << "? " << 2 << ' ' << R + 2 << '\n';
    int amount;
    cin >> amount;
    arr[1] = amount - arr[2];
    arr[0] = total - arr[1];   
    cout << "! ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';


}

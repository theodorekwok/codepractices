#include <bits/stdc++.h>

using namespace std;

bool is_prime(unsigned long long val) {
    if (val == 2) {
        return true;
    }

    if (val % 2 == 0) {
        return false;
    }

    for (unsigned long long i = 3; i <= sqrt(val); i += 2) {
        if (val % i == 0) {
            return false;
        }
    }
    return true;
}

void get_sequence(unsigned long long n) {
    if (n % 2 != 0 && is_prime(n)) {
        cout << 1 << '\n';
        cout << n << '\n';
        return;
    }
    vector<unsigned long long> store_primes;
    store_primes.push_back(2);
    
    for (unsigned long long i = 3; i <= sqrt(n); i += 2) {
        if (is_prime(i)) {
            store_primes.push_back(i);
        }
    }

    unsigned long long n_store = n;
    unsigned long long max_length = 0;
    unsigned long long max_factor = 1;
    for (int i = 0; i < store_primes.size(); i++) {
        unsigned long long factor_length = 0;
        while (n % store_primes[i] == 0) {
            n /= store_primes[i];
            factor_length++;
        }
        if (factor_length > max_length) {
            max_length = factor_length;
            max_factor = store_primes[i];
        }
    }

    cout << max_length << '\n';
    unsigned long long last_val = 1;
    for (int i = 0; i < max_length - 1; i++) {
        cout << max_factor << ' ';
        last_val *= max_factor;
    }   
    unsigned long long value = n_store/last_val;
    cout << value << '\n';
    
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        cin >> n;
        get_sequence(n);
    }
    return 0;    
}

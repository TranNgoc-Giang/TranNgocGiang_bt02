#include <iostream>
using namespace std;

int sum_1_to_n(int n) {
    int s = 0;
    for(int i = 1; i <= n; i++) {
        s += i; // Sum up the numbers from 1 to n
    }
    return s;
}

int main() {
    int n = 5;
    cout << "Tong 1..n = " << sum_1_to_n(n) << endl; // Output: 15
    return 0;
}
#include <iostream>

using namespace std;

int gcd(int a, int b) {

    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    return (a < 0) ? -a : a;
}

int ex2(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {

    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    int res = ex2(a, b);

    cout << "There is GCD: " << res;

    return 0;
}
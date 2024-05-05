#include <iostream>
#include <cmath>
bool ShipChek(long double n, long double k) {
    if (((k + 3) * (k * k + 6 * k + 2) / 6) <= n) {
        return true;
    }
    return false;
}
long long binP(long double n) {
    if (n == 0) {
        return 0;
    }
    long long left = 0, right = n, res = 0;
    while (left <= right) {
        long double mid = left + (right - left) / 2;
        if (ShipChek(n, mid)) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res + 1;
}
int main() {
    long double n;
    std::cin >> n;
    long long maxK = binP(n);
    std::cout << maxK;
    return 0;
}

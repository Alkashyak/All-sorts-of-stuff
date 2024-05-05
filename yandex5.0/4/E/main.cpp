#include <iostream>
#include <cmath>
#include <utility>
std::pair<long long, long long> findK(long long n) {
    long long diagonal = std::floor((std::sqrt(8 * n) - 1) / 2) + 1;
    long long sum_diag = (diagonal * (diagonal - 1)) / 2 + 1;
    long long num_in_diag = n - sum_diag + 1;
    long long boobus = num_in_diag;
    long long aboba = diagonal + 1 - num_in_diag;
    if (diagonal % 2 == 0) {
        std::swap(boobus, aboba);
    }
    return std::make_pair(boobus, aboba);
}
int main() {
    long long n;
    std::cin >> n;
    std::pair<long long, long long> fraction = findK(n);
    std::cout << fraction.first << "/" << fraction.second;
    return 0;
}

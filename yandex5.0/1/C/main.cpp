#include <iostream>
int main() {
    int n; 
    long sum = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        sum += (k % 4 < 3) ? k / 4 + k % 4 : k / 4 - k % 4 + 5;
    }
    std::cout << sum;
    return 0;
} // решил сделать по-человечески 

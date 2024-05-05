#include <iostream>
#include <string>
int main() {
    std::string aboba1, aboba2;
    int n;
    std::cin >> aboba1;
    std::cin >> aboba2;
    std::cin >> n;
    int K1 = aboba1[0] - '0';
    int K1F = aboba2[0] - '0';
    int K2 = aboba1[2] - '0';
    int K2F = aboba2[2] - '0';
    int sum1 = K1 + K1F;
    int sum2 = K2 + K2F;
    if (sum1 > sum2) {
        std::cout << 0;
    }
    else {
        if (n == 1) {
            if (sum1 == sum2) {
                if (K1F > K2) {
                    std::cout << 0;
                }
                else {
                    std::cout << 1;
                }
            }
            else {
                if ((sum2 - sum1) + K1F <= K2) {
                    std::cout << sum2 - sum1 + 1;
                }
                else {
                    std::cout << sum2 - sum1;
                }
            }
        }
        else {
            if (sum1 == sum2) {
                if (K1 > K2F) {
                    std::cout << 0;
                }
                else {
                    std::cout << 1;
                }
            }
            else {
                if (K1 > K2F) {
                    std::cout << sum2 - sum1;
                }
                else {
                    std::cout << sum2 - sum1 + 1;
                }
                
            }
        }
    }
    return 0;
}

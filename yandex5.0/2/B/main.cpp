#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int K;
    int N;
    std::cin >> N;
    std::cin >> K;
    std::vector<int> Aboba;
    int maxm = 0;
    for(int i = 0; i < N; i++){
        int num;
        std::cin >> num;
        Aboba.push_back(num);
    }
    for (int i = 0; i < N; i++) {
        for (int k = 1; k <= K; k++) {
            if ((i + K) < N) {
                if ((Aboba[i + k] - Aboba[i]) > maxm) {
                    maxm = Aboba[i + k] - Aboba[i];
                }
            }
            else {
                K--;
            }
        }
    }
    std::cout << maxm;

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> xboba;
    std::vector<int> yboba;

    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        xboba.push_back(x);
        int y;
        std::cin >> y;
        yboba.push_back(y);
    }

    int res = N * 4;

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            if ((std::abs(xboba[i] - xboba[k]) == 1) && (std::abs(yboba[i] - yboba[k]) == 0) ||
                (std::abs(yboba[i] - yboba[k]) == 1) && (std::abs(xboba[i] - xboba[k]) == 0)) {
                res--;
            }
        }
    }

    std::cout << res;
    return 0;
}

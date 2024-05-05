#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int K;
    std::vector<int> AbobusX;
    std::vector<int> AbobusY;
    std::cin >> K;
    for (int i = 0; i < K; i++) {
        int x;
        std::cin >> x;
        AbobusX.push_back(x);
        int y;
        std::cin >> y;
        AbobusY.push_back(y);
    }
    std::sort(AbobusX.begin(), AbobusX.end());
    std::sort(AbobusY.begin(), AbobusY.end());
    std::cout << AbobusX[0] << " " << AbobusY[0] << " " << AbobusX[AbobusX.size() - 1] << " " << AbobusY[AbobusY.size() - 1];
    return 0;
}

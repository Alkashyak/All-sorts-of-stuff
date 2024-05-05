#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
int main() {
    int N, k;
    std::cin >> N;
    std::cin >> k;
    std::map<int, std::vector<int>> aboba; 
    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        aboba[num].push_back(i);
    }
    for (auto& [num, positions] : aboba) { 
        if (positions.size() >= 2) {
            std::sort(positions.begin(), positions.end());
            for (size_t i = 0; i < positions.size() - 1; i++) { 
                if (std::abs(positions[i + 1] - positions[i] - 1) < k) {
                    std::cout << "YES";
                    return 0;
                }
            }
        }
    }
    std::cout << "NO";
    return 0;
}

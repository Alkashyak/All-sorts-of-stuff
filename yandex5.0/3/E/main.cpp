#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
int main() {
    std::vector<std::unordered_set<int>> aboba(3);
    for (int i = 0; i < 3; i++) {
        int N;
        std::cin >> N;
        for (int j = 0; j < N; j++) {
            int num;
            std::cin >> num;
            aboba[i].insert(num);
        }
    }
    std::unordered_set<int> res;
    for (int i = 0; i < 3; i++) {
        for (int num : aboba[i]) {
            int count = 0;
            for (int j = 0; j < 3; j++) {
                if (aboba[j].count(num) > 0) {
                    count++;
                }
            }
            if (count >= 2) {
                res.insert(num);
            }
        }
    }
    std::vector<int> res2(res.begin(), res.end());
    std::sort(res2.begin(), res2.end());
    for (int num : res2) {
        std::cout << num << " ";
    }
    return 0;
}

#include <iostream>
#include <map>
#include <set>
#include <string>
int main() {
    int N;
    int ch = 0;
    std::cin >> N;
    std::map<std::string, int> aboba;
    for (int i = 0; i < N; ++i) {
        int N2;
        std::cin >> N2; 
        for (int i = 0; i < N2; i++) {
            std::string abc;
            std::cin >> abc; 
            if (aboba.find(abc) != aboba.end()) { 
                aboba[abc]++; 
            }
            else {
                aboba[abc] = 1; 
            }
            if (aboba[abc] >= N) {
                ch++;
            }
        }
    }
    std::cout << ch << "\n";
    for (const auto& entry : aboba) {
        if (entry.second == N) {
            std::cout << entry.first << " ";
        }
    }

    return 0;
}

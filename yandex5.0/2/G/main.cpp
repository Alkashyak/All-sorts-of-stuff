#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        int c1 = 0;
        int c2 = 1;
        int mn = 100000;
        std::vector<int> aboba;
        for (int j = 0; j < n; j++) {
            int a;
            std::cin >> a;
            if (a <= mn) {
                mn = a;
            }
            if (mn >= (c1 + 1)) {
                c1++;
            }
            else {
                aboba.push_back(c1);
                c1 = 1; 
                c2++;
                mn = a;
            }
        }
        aboba.push_back(c1); 
        std::cout << c2 << "\n";
        for (int j : aboba) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

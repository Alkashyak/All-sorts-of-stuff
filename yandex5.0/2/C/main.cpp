#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> Aboba;
    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        Aboba.push_back(num);
    }
    sort(Aboba.begin(), Aboba.end());
    int sum = 0;
    int mx = Aboba[Aboba.size() - 1];
    for (int i = 0; i < N - 1; i++) {
        sum += Aboba[i];
    }
    if (sum < mx) {
        std::cout << mx - sum;
    }
    else if(sum == mx){
        std::cout << mx * 2;
    }
    else {
        std::cout << mx + sum;
    }
    return 0;
}

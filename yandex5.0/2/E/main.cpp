#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

struct Pair {
    int first;
    int second;
};

int main() {
    int N;
    int io = -1;
    int ip = -1;
    bool flag = true;
    long mx = LONG_MIN;
    int mxo = 0;
    std::cin >> N;
    std::vector<Pair> aboba;
    aboba.reserve(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        aboba.emplace_back(Pair{ a, b });
        if (a - b > 0) {
            flag = false;
        }
    }
    if (flag) {
        for (int i = 0; i < N; i++) {
            if (aboba[i].first > mxo) {
                mxo = aboba[i].first;
                io = i;
            }
        }
        std::cout << mxo << "\n";
        std::cout << io + 1 << " ";
        for (int i = 0; i < N; i++) {
            if (i != io) {
                std::cout << i + 1 << " ";
            }
        }
        return 0;
    }
    long sum = 0;
    for (const auto& pair : aboba) {
        if (pair.first - pair.second > 0) {
            sum += pair.first - pair.second;
        }
    }

    for (int i = 0; i < N; i++) {
        if (aboba[i].first - aboba[i].second > 0) {
            long current_sum = sum - (aboba[i].first - aboba[i].second);
            if (current_sum + aboba[i].first > mx) {
                ip = i;
                mx = current_sum + aboba[i].first;
            }
        }
        else {
            if (aboba[i].first > mxo) {
                mxo = aboba[i].first;
                io = i;
            }
        }
    }

    if (io != -1 && ip != -1) {
        mx = std::max(mx, ((mx - aboba[ip].second) + mxo));
        std::cout << mx << "\n";
        for (int i = 0; i < N; i++) {
            if (aboba[i].first - aboba[i].second > 0 && i != ip) {
                std::cout << i + 1 << " ";
            }
        }
        std::cout << ip + 1 << " " << io + 1 << " ";
        for (int i = 0; i < N; i++) {
            if (aboba[i].first - aboba[i].second <= 0 && i != io) {
                std::cout << i + 1 << " ";
            }
        }
    }
    else if (io != -1 && ip == -1) {
        std::cout << mxo << "\n";
        std::cout << io + 1;
        for (int i = 0; i < N; i++) {
            if (i != io) {
                std::cout << i + 1 << " ";
            }
        }
    }
    else if (io == -1 && ip != -1) {
        std::cout << mx << "\n";
        for (int i = 0; i < N; i++) {
            if (i != ip) {
                std::cout << i + 1 << " ";
            }
        }
        std::cout << ip + 1 << " ";
    }
    return 0;
}

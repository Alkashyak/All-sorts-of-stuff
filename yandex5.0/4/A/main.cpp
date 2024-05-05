#include <vector>
#include <iostream>
#include <algorithm>
int binP(const std::vector<int>& arr, int start, int end) {
    if (start > end) {
        return 0;
    }
    int left = 0, right = arr.size() - 1;
    int startI = -1, endI = -1;
    while (left <= right) {
        int m = left + (right - left) / 2;
        if (arr[m] >= start) {
            startI = m;
            right = m - 1;
        }
        else {
            left = m + 1;
        } 
    }
    left = 0;
    right = arr.size() - 1;
    while (left <= right) {
        int m = left + (right - left) / 2;
        if (arr[m] <= end) {
            endI = m;
            left = m + 1;
        }
        else {
            right = m - 1;
        }
    }
    if (startI == -1 || endI == -1) {
        return 0;
    }
    return endI - startI + 1;
}
int main() {
    int N;
    std::cin >> N;
    std::vector<int> aboba;
    std::vector<int> res;
    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        aboba.push_back(num);
    }
    std::sort(aboba.begin(), aboba.end());
    int K;
    std::cin >> K;
    for (int i = 0; i < K; i++) {
        int L;
        int R;
        std::cin >> L >> R; 
        res.push_back(binP(aboba, L, R));
    }
    for (int i : res) {
        std::cout << i << " ";
    }
    return 0;
}

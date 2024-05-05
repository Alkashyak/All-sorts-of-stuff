#include <iostream> 
#include <vector> 
#include <algorithm>
int findMx(const std::vector<int>& nums, int u, int b) {
    int max_num = nums[u];
    for (int i = u; i <= b; ++i) {
        max_num = std::max(max_num, nums[i]);
    }
    return max_num;
}
int main() {
    int n, a, b, k;
    std::vector<int> aboba;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        aboba.push_back(num);
    }
    std::cin >> a;
    std::cin >> b;
    std::cin >> k;
    int a1, b1;
    a1 = (a - 1) / k;
    b1 = (b - 1) / k;
    bool flag = false;
    if ((b1 - a1) >= n) {
        flag = true;
    }
    int mx = -1;
    if (b1 >= aboba.size() || a1 >= aboba.size()) {
        if (b1 >= aboba.size()) {
            int bb = b1 % aboba.size();
            b1 = bb;
        }
        if (a1 >= aboba.size()) {
            int aa = a1 % aboba.size();
            a1 = aa;
        }
    }

    if (flag) {
        mx = std::max(mx, findMx(aboba, 0, aboba.size() - 1));
    }
    else {
        if (a1 == 0 || b1 == 0) {
            if (a1 == 0 && b1 == 0) {
                mx = mx = std::max(mx, aboba[0]);
            }
            else {
                if (a1 == 0) {
                    mx = std::max(mx, findMx(aboba, 0, b1));
                    mx = std::max(mx, findMx(aboba, aboba.size() - b1, aboba.size() - 1));
                }
                else {
                    mx = std::max(mx, findMx(aboba, a1, aboba.size() - 1));
                    mx = std::max(mx, findMx(aboba, 0, b1));
                    mx = std::max(mx, findMx(aboba, 0, aboba.size() - a1));
                }
            }
        }
        else if (a1 < b1) {
            mx = std::max(mx, findMx(aboba, a1, b1));
            mx = std::max(mx, findMx(aboba, aboba.size() - b1, aboba.size() - a1));
        }
        else if (a1 > b1) {
            mx = std::max(mx, findMx(aboba, a1, aboba.size() - 1)); 
            mx = std::max(mx, findMx(aboba, 0, b1)); 
            mx = std::max(mx, findMx(aboba, 0, aboba.size() - a1)); 
            mx = std::max(mx, findMx(aboba, aboba.size() - b1, aboba.size() - 1)); 
        }
        else {
            mx = std::max(mx, findMx(aboba, a1, b1));
            mx = std::max(mx, findMx(aboba, aboba.size() - b1, aboba.size() - a1));
        }
    }
    std::cout << mx;
    return 0;
}

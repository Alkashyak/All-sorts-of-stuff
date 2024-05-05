#include <iostream>
#include <map>
#include <string>
int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::map<char, int> abobaMap;
    for (char c = 'a'; c <= 'z'; ++c) {
        abobaMap[c] = 0;
    }
    for (char c : s1) {
        abobaMap[c]++;
    }
    for (char c : s2) {
        abobaMap[c]--;
    }
    bool flag = true;
    for (auto& pair : abobaMap) {
        if (pair.second != 0) {
            flag = false; 
            break;
        }
    }
    if (flag) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}

#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <algorithm>
int main() {
    std::unordered_set<std::string> abobus;
    std::string abb;
    std::getline(std::cin, abb);
    std::istringstream iss(abb);
    std::string word;
    while (iss >> word) {
        abobus.insert(word);
    }
    std::string text;
    std::getline(std::cin, text);
    std::istringstream issText(text);
    std::string haduken; 
    while (issText >> haduken) {
        std::string res = haduken; 
        std::vector<std::string> amogus;
        for (int i = 1; i <= haduken.size(); ++i) {
            std::string prefix = haduken.substr(0, i);
            if (abobus.find(prefix) != abobus.end()) {
                amogus.push_back(prefix);
            }
        }
        if (!amogus.empty()) {
            res = *std::min_element(amogus.begin(), amogus.end(), [](const std::string& a, const std::string& b) {
                return a.size() < b.size();
                });
        }
        std::cout << res << " ";
    }
    return 0;
}

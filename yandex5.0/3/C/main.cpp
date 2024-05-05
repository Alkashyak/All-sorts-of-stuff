#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <unordered_map> 
 
int booba(int n, std::vector<int> a){ 
    if(n == 1) return 0; 
    int res = a.size(); 
    std::unordered_map<int,int> cnt; 
    for(auto& ele : a) cnt[ele]++; 
    std::sort(a.begin(), a.end()); 
    auto uniq = std::unique(a.begin(),a.end()); 
    a.erase(uniq, a.end()); 
    if(a.size() == 1) return 0; 
    int max_nums = 0; 
    for(int i = 1; i < a.size(); i++) 
    if(abs(a[i] - a[i - 1]) <= 1)max_nums = std::max(max_nums,cnt[a[i]] + cnt[a[i-1]]); 
    return max_nums == 0 ? res-1 : res - max_nums; 
} 
 
int main(){ 
    int n; 
    std::vector<int> a; 
    std::cin >> n; 
    while(n > 0){ 
        n--; 
        int temp; 
        std::cin >> temp; 
        a.push_back(temp); 
    } 
    std::cout << booba(n,a); 
}

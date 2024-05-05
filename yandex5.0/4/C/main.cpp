#include <iostream>
#include <vector>
#include <utility> 

std::vector<long> FindIx(long n, long m, const std::vector<long>& nums, const std::vector<std::pair<long, long>>& queries) {
    std::vector<long> prefixSum(n + 1); 
    for (long i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }
    std::vector<long> result; 
    for (const auto& query : queries) {
        long l = query.first; 
        long s = query.second; 
        long low = 0, high = n - l;
        long index = -1; 
        while (low <= high) {
            long mid = low + (high - low) / 2;
            long segmentSum = prefixSum[mid + l] - prefixSum[mid]; 
            if (segmentSum == s) {
                index = mid + 1; 
                break;
            } else if (segmentSum < s) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        result.push_back(index);
    }
    return result;
}

int main() {
    long n, m;
    std::cin >> n >> m;
    std::vector<long> nums(n);
    for (long i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    std::vector<std::pair<long, long>> queries(m);
    for (long i = 0; i < m; ++i) {
        std::cin >> queries[i].first >> queries[i].second;
    }
    std::vector<long> indices = FindIx(n, m, nums, queries);
    for (long index : indices) {
        std::cout << index << std::endl;
    }
    return 0;
}

#include <vector>
#include <unordered_map>
#include <queue>

class Solution { 
public: 
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) { 
        std::unordered_map<int, int> elem_counts; 
        for(int elem : nums){ 
            elem_counts[elem]++; 
        } 

        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int, int>>, 
                            std::greater<std::pair<int, int>>> minHeap; 

        for (const auto& pair : elem_counts){ 
            minHeap.push({pair.second, pair.first}); 
            if (minHeap.size() > k){ 
                minHeap.pop(); 
            } 
        } 

        std::vector<int> result(k);
        for (int i = k - 1; i >= 0; --i) {
            result[i] = minHeap.top().second;
            minHeap.pop();
        }

        return result;
    } 
};

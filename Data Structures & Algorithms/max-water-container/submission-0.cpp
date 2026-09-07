#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& heights) {
        int max_water = 0;
        int left = 0;
        int right = heights.size() - 1;
        
        while (left < right) {
            int width = right - left;
            int current_height = std::min(heights[left], heights[right]);
            int current_water = width * current_height;
            
            max_water = std::max(max_water, current_water);
            
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};

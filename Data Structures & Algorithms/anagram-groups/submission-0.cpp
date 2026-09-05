class Solution { 
public: 
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) { 
        std::unordered_map<std::string, std::vector<std::string>> groups; 
        
        for(std::string elem : strs){ 
            std::string sorted_elem = elem; 
            std::sort(sorted_elem.begin(), sorted_elem.end()); 
            groups[sorted_elem].push_back(elem); 
        } 
        
        std::vector<std::vector<std::string>> grouped_anagrams = {}; 
        for (auto& pair : groups){ 
            
            grouped_anagrams.push_back(pair.second); 
        } 
        
        return grouped_anagrams; 
    } 
};
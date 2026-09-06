class Solution { 
public: 
    string encode(vector<string>& strs) { 
        string result = ""; 
        for (string elem : strs) {
            std::transform(elem.begin(), elem.end(), elem.begin(), [](char c) { return c + 1; });
            result += std::to_string(elem.length()) + "#" + elem;
        } 
        return result; 
    } 

    vector<string> decode(string s) { 
        vector<string> result;
        size_t i = 0;
        while (i < s.length()) {
            size_t j = s.find('#', i);
            int len = std::stoi(s.substr(i, j - i));
            string elem = s.substr(j + 1, len);
            std::transform(elem.begin(), elem.end(), elem.begin(), [](char c) { return c - 1; });
            result.push_back(elem);
            i = j + 1 + len;
        }
        return result; 
    } 
};

class Solution {
public:
    array<char, 26> getKey(const string& str)
    {
        array<char, 26> count{};
        for(const char &s : str)
            count[s - 'a'] ++;
        
        return count;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<char, 26>, vector<string>> ans;
        vector<vector<string>> result;
        
        for(auto &&str : strs)
            ans[getKey(str)].push_back(move(str));
     
        for(auto &&it : ans)
            result.push_back(move(it.second));
        
        return result;
    }
};

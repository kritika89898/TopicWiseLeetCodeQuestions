class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(auto w:strs){
            string temp = w;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(w);
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
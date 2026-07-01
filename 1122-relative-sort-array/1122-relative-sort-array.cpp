class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(auto x:arr1){
            mp[x]++;
        }
        vector<int> ans;
        for(auto v:arr2){
            while(mp[v]-- >0){
                ans.push_back(v);
            }
            mp.erase(v);
        }
        vector<int> remaining;
        for (auto& [num, count] : mp)
            for (int i = 0; i < count; i++)
                remaining.push_back(num);
        sort(remaining.begin(), remaining.end());  // Ascending order
        ans.insert(ans.end(), remaining.begin(), remaining.end());
        return ans;
    }
};
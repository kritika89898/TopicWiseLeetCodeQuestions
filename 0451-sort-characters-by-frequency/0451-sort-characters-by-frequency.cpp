class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto x:s){
            mp[x]++;
        }
        priority_queue<pair<int ,char>> pq;
        for(auto p : mp){
            pq.push({p.second,p.first});
        }
        string ans = "";
        while(!pq.empty()){
            auto[count,ch] = pq.top();
            pq.pop();
            ans.append(count,ch);
        }
        return ans;
    }
};
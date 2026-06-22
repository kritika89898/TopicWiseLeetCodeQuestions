class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        if(n<7) return 0;
        int cnt = 0;
        unordered_map<char,int> mp;
        for(auto& ch:text){
            mp[ch]++;
        }
        unordered_map<char,int> w;
        string word = "balloon";
        for(auto& ch:word){
            w[ch]++;
        }
        int ans = INT_MAX;
        for (auto &p : w) {
            ans = min(ans, mp[p.first] / p.second);
        }

        return ans;
    }
};
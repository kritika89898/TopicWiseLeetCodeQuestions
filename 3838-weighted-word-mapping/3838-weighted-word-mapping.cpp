class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        string ans = "";
        for(auto x:words){
            int sum = 0;
            for(auto ch : x){
                sum = sum + weights[ch - 'a'];
            }
            int idx = sum%26;
            ans = ans + char('z'- idx);
        }
        return ans;
    }
};
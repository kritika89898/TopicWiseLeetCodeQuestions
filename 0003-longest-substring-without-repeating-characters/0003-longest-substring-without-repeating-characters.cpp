class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0;
        int l = 0;
        int n = s.size();
        int r = 0;
        unordered_set<char> seen;
        while(r<n){
            if(seen.find(s[r]) == seen.end()){
                seen.insert(s[r]);
                mx = max(mx,r-l+1);
                r++;
            }else{
                seen.erase(s[l]);
                l++;
            }
        }
        return mx;
    }
};
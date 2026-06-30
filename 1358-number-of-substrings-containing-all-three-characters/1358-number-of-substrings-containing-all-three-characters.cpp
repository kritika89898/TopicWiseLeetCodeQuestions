class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0 ;
        int cnt = 0;
        unordered_map<char,int>mp;
        while(j<s.size()){
            mp[s[j]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                cnt =  cnt + s.size()-j;
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return cnt;
    }
};
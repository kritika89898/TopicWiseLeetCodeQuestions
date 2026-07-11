class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> vec(3,0);
        int l = 0;
        int ans = 0;
        for(int r = 0 ; r < s.size() ; r++){
            vec[s[r] - 'a']++;
            while(vec[0]>0 && vec[1]>0 && vec[2]>0){
                vec[s[l]-'a']--;
                l++;
            }
            ans = ans + l;
        }
        return ans;
    }
};
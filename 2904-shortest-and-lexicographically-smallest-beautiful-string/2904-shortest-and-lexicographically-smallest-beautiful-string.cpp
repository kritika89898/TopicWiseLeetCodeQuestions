class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0;
        int n = s.size();
        string ans = "";
        int cnt = 0;
        for(int r = 0 ; r < n ;r++){
            if(s[r] == '1'){
                cnt++;
            }
            while(k == cnt){
                string curr = s.substr(l,r-l+1);
                if(ans == "" || ans.size()>curr.size() || (ans.size() == curr.size() && ans>curr)){
                    ans = curr;
                }
                if(s[l] == '1') cnt--;
                l++;
            }
        }
        return ans;
    }
};
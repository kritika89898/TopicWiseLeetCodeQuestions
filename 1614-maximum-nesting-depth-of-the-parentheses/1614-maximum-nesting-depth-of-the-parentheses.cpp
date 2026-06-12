class Solution {
public:
    int maxDepth(string s) {
        int cnt  = 0;
        int mx = 0;
        for(auto x:s){
            if(x == '('){
                cnt++;
                mx = max(mx,cnt);
            }else if( x == ')'){
                cnt--;
                
            }
        }
        return mx;
    }
};
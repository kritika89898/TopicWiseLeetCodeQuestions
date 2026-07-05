class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int mx = events[0][1];
        int n = events.size();
        int ans = events[0][0];
        for(int i = 1 ; i < n ; i++){
            if((events[i][1]-events[i-1][1]) > mx){
                ans = events[i][0];
                mx = events[i][1]-events[i-1][1];
            }else if((events[i][1]-events[i-1][1]) == mx){
                ans = min(ans,events[i][0]);
            }
        }
        return ans;

    }
};
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0;
        int curr = 0 ;
        for(auto x:gain){
            curr = curr+ x;
            mx = max(curr,mx);
        }
        return mx;
    }
};
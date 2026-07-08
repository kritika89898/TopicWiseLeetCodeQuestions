class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        
        long long s= 0 ;
        for(int i = 0 ; i < n-1 ; i++){
            int mn = INT_MAX;
            int mx = INT_MIN;
            mn= min(mn,nums[i]);
            mx = max(mx,nums[i]);
            for(int j = i+1 ; j < n ;j++){
                mn= min(mn,nums[j]);
                mx = max(mx,nums[j]);
                s = s + mx-mn;
            }
            
        }
        return s;
    }
};
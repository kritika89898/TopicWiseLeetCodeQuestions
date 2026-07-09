class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int r = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            
            if(nums[i] == 0){
                k--;
            }
            
            while(k<0){
                if(nums[r] == 0){
                    k++;
                }
                r++;
            }
            ans = max(ans, i-r+ 1);
        }
        return ans;
    }
};
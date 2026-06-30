class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int mn = *min_element(nums.begin(),nums.end());
        int cnt  = 0;
        for(auto x:nums){
            if(x%mn != 0){
                return 1;
            }
            if(x == mn){
                cnt++;
            }
        }
        return (cnt+1)/2;
    }
};
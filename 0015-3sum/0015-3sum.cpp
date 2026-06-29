class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
      
       int n = nums.size();
       set<vector<int>> st;
       for(int i = 0 ; i < n ; i++){
        int j = i+1;
        int k=n-1;
        while(j<k){
            int s = nums[i]+nums[j]+nums[k];
            if(s == 0){
                st.insert({nums[i],nums[j],nums[k]});
                j++;
                k--;
            }else if(s>0){
                k--;
            }else{
                j++;
            }
        }
       }
       vector<vector<int>> ans(st.begin(),st.end());
       return ans;

    }
};
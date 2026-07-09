class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        
        
        vector<int> comp(n);
        
        comp[0] = 0;
        for(int i = 0 ; i < n-1 ; i++){
            if(nums[i+1] - nums[i] <= maxDiff){
                comp[i+1] = comp[i];
            }else{
                comp[i+1] = comp[i]+1;
            }
        }

        for(auto& q:queries){
            int a = q[0];
            int b = q[1];
            ans.push_back(comp[a] == comp[b]);
        }
        return ans;
    }
};
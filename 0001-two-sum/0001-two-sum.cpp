class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> nsum;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            nsum.push_back({nums[i],i});
        }
        sort(nsum.begin(),nsum.end());
        int l = 0;
        int r = n-1;
        while(l<r){
            int s = nsum[l].first + nsum[r].first;
            if(s==target){
                return {nsum[l].second,nsum[r].second};
            }else if(s<target){
                l++;
            }else{
                r--;
            }
        }
        return {-1,-1};

    }
};
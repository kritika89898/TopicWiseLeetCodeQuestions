class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> seen;
        int mx = 1;
        for(auto x:nums){
            seen.insert(x);
        }
        for(auto x:seen){
            if(seen.find(x-1) == seen.end()){
                int cnt = 1;
                int num = x;
                while(seen.find(num+1) != seen.end()){
                    cnt++;
                    num = num+1;
                }
                mx = max(mx,cnt);
            }
            
        }
        return mx;
    }
};
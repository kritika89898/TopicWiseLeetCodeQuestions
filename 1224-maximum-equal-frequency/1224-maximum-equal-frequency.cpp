class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        vector<int> freq(100001, 0);
        vector<int> count(100001, 0);
        int max_f = 0;
        int ans = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            
            if (freq[num] > 0) {
                count[freq[num]]--;
            }
            
            freq[num]++;
            count[freq[num]]++;
            max_f = max(max_f, freq[num]);
            
            int L = i + 1;
            
            if (max_f == 1) {
                ans = L;
            } else if (count[max_f] * max_f + 1 == L) {
                ans = L;
            } else if (count[max_f] == 1 && count[max_f - 1] * (max_f - 1) + max_f == L) {
                ans = L;
            }
        }
        
        return ans;
        

    }
};
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int, int> freq;
        int prefix = 0;
        freq[0] = 1; // base case

        for (int x : nums) {
            if (x == target) prefix++;
            else prefix--;

            // count how many previous prefixes are less than current
            for (auto& [p, count] : freq) {
                if (p < prefix) ans += count;
            }
            freq[prefix]++;
        }
        return ans;
    }
};
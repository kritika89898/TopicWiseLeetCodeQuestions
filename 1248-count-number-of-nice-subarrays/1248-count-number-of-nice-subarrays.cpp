class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         int left = 0;
        int odd = 0;
        int prefixEven = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] % 2) {
                odd++;
                prefixEven = 0;
            }

            while (odd == k) {
                prefixEven++;

                if (nums[left] % 2)
                    odd--;

                left++;
            }

            ans += prefixEven;
        }

        return ans;
    }
};
class Solution {
public:
    
    int beautySum(string s) {
         int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> cnt(26, 0);

            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;

                int mx = 0;
                int mn = INT_MAX;

                for (int f : cnt) {
                    if (f > 0) {
                        mx = max(mx, f);
                        mn = min(mn, f);
                    }
                }

                ans += mx - mn;
            }
        }

        return ans;

    }
};
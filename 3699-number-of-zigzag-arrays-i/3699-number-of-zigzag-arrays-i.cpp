class Solution {
public:
    static const int MOD = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m), down(m), nu(m), nd(m);

        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {
            int cur = 0;
            for (int i = 0; i < m; i++) {
                nu[i] = cur;
                cur += down[i];
                if (cur >= MOD) cur -= MOD;
            }

            cur = 0;
            for (int i = m - 1; i >= 0; i--) {
                nd[i] = cur;
                cur += up[i];
                if (cur >= MOD) cur -= MOD;
            }

            swap(up, nu);
            swap(down, nd);
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans += up[i];
            if (ans >= MOD) ans -= MOD;
            ans += down[i];
            if (ans >= MOD) ans -= MOD;
        }

        return ans;
    }
};
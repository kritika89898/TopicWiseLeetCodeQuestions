class Solution {
public:
    long long gcd(long long x, long long y) {
        return y == 0 ? x : gcd(y, x % y);
    }

    long long lcm(long long x, long long y) {
        return x / gcd(x, y) * y;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long low = 1, high = 2e9; // search space
        long long ab = lcm(a, b), bc = lcm(b, c), ac = lcm(a, c);
        long long abc = lcm(a, bc);

        while (low < high) {
            long long mid = (low + high) / 2;
            long long count = mid / a + mid / b + mid / c
                            - mid / ab - mid / bc - mid / ac
                            + mid / abc;
            if (count < n)
                low = mid + 1;
            else
                high = mid;
        }
        return (int)low;
    }
};

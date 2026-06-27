class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorv = x ^ y;      // XOR gives differing bits
        int cnt = 0;
        while (xorv) {
            cnt += xorv & 1;   // count set bits
            xorv >>= 1;        // shift right
        }
        return cnt;
        
    }
};
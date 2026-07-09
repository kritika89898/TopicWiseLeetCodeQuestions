class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
         long long total = 0;
        long long mx = 0;
        
        for(int x : milestones) {
            total += x;
            mx = max(mx, (long long)x);
        }
        
        long long others = total - mx;
        
        if(mx <= others + 1) {
            return total;
        }
        
        return 2 * others + 1;
    }
};
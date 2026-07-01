class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int r = 0;
        int l = n-1;
        int ans = 0;
        while(r<l){
            int area = (l-r)*min(height[l],height[r]);
            ans = max(ans,area);
            if(height[l]<height[r]){
                l--;
            }else{
                r++;
            }
        }
        return ans;
    }
};
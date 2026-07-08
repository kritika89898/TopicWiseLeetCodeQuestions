class Solution {
public:
    void solve(vector<int>& candidates, int target,set<vector<int>>& st,vector<int> comb,int i){
        int n = candidates.size();
        if(n == i || target<0){
            return;
        }
        if(target == 0){
            st.insert(comb);
            return;
        }
        comb.push_back(candidates[i]);
        //include 1
        solve(candidates,target-candidates[i],st,comb,i+1);
        //include many
        solve(candidates,target-candidates[i],st,comb,i);
        comb.pop_back();

        //exclude
        solve(candidates,target,st,comb,i+1);
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     
      set<vector<int>> st;
      vector<int> comb;
      solve(candidates,target,st,comb,0);
       vector<vector<int>> ans(st.begin(),st.end());
       return ans;
    }
};
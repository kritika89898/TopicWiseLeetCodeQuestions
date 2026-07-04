class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<bool>& visited,int st){
        visited[st] = true;
        int n = isConnected.size();
        for(int i = 0 ; i < n ;i++){
            if(isConnected[st][i]==1 && !visited[i]){
                dfs(isConnected,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int cnt = 0;
        for(int i = 0 ; i < n ;i++){
            if(!visited[i]){
                dfs(isConnected,visited,i);
                cnt++;
            }
        }
        return cnt;
    }
};
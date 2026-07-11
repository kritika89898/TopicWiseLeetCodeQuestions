class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<bool>& visited ,int i , int &v, int &e){
        visited[i] = true;
        v++;
        for(auto nei : adj[i]){
            e++;
            if(!visited[nei]){
                
                dfs(adj,visited,nei,v,e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                int v = 0;
                int e = 0;
                dfs(adj,visited,i,v,e);
                e = e/2;
                if(e == (v *(v-1))/2) ans++;

            }

        }
        return ans;
    }
};
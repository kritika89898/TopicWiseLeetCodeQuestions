class Solution {
public:
    bool dfs(vector<vector<int>> adj,int i ,vector<bool> parent,vector<bool> visited){
        visited[i] = true;
        parent[i] = true;
        for(auto vec:adj[i]){
            if(!visited[vec] && dfs(adj,vec,parent,visited)){
                return true;
            }else if(parent[vec]){
                return true;
            }
        }
        parent[i] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses,false);
        vector<bool> parent(numCourses,false);
        for(auto p:prerequisites){
            int u = p[0];
            int v= p[1];
            adj[v].push_back(u);
        }
        for(int i = 0 ; i < numCourses ;i++){
          if(!visited[i] && dfs(adj,i,parent,visited)){
            return false;
          }
        }
        return true;
    }
};
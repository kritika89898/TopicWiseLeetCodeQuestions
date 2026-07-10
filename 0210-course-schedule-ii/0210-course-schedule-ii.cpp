class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        queue<int> q;
        for(auto p : prerequisites){
            int u = p[0];
            int v = p[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto nei:adj[node]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};
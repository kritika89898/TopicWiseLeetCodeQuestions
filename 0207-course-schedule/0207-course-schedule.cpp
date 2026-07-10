class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int cnt = 0;
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        vector<int> indegree(numCourses,0);
        
        for(auto& p:prerequisites){
            int u = p[0];
            int v = p[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto nei:adj[node]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        return cnt == numCourses;
        
    }
};
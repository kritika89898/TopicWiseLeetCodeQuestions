class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                     dist[i][j] = 0;
                }
            }
        }
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(auto& d:dir){
                int ni = d[0]+i;
                int nj = d[1]+j;

                if(ni>=0 && nj>=0 && ni<n && nj<m && dist[ni][nj]==-1){
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni,nj});
                } 
            }
        }
        return dist;
    }
};